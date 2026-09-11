# cmake/Bootstrap.cmake
# Handles building fbc from pre-generated C sources when no existing fbc is available.
#
# Bootstrap modes:
#   "native"    - Use an existing fbc to compile .bas sources directly
#   "bootstrap" - Compile pre-generated .c sources to build fbc

# A source build must not change merely because another fbc happens to be in
# PATH.  The bundled generated C sources are therefore the default bootstrap
# input.  Developers can explicitly opt in to a native compiler build.
if(FB_USE_SYSTEM_FBC)
    find_program(FBC_EXECUTABLE fbc HINTS ${CMAKE_SOURCE_DIR}/bin ENV PATH)

    if(FBC_EXECUTABLE)
        execute_process(
            COMMAND ${FBC_EXECUTABLE} --version
            OUTPUT_VARIABLE _fbc_version_output
            ERROR_QUIET
            OUTPUT_STRIP_TRAILING_WHITESPACE
            RESULT_VARIABLE _fbc_result
        )
        if(_fbc_result EQUAL 0)
            message(STATUS "Found existing fbc: ${FBC_EXECUTABLE}")
            message(STATUS "  ${_fbc_version_output}")
            set(FB_BOOTSTRAP_MODE "native")
        else()
            set(FBC_EXECUTABLE "")
        endif()
    endif()
endif()

if(NOT FBC_EXECUTABLE)
    # A bootstrap source encodes the compiler's host OS and architecture.  It
    # must therefore match FB_TARGET_ID exactly; using a nearby platform's C
    # sources produces a compiler with the wrong runtime layout.
    set(FB_BOOTSTRAP_DIR "${CMAKE_SOURCE_DIR}/bootstrap/${FB_TARGET_ID}")

    if(EXISTS "${FB_BOOTSTRAP_DIR}")
        file(GLOB _fb_bootstrap_input_sources "${FB_BOOTSTRAP_DIR}/*.c")
        if(_fb_bootstrap_input_sources)
            find_package(Python3 COMPONENTS Interpreter REQUIRED)
            execute_process(
                # MSYS Python expects POSIX paths while CMake on native
                # Windows passes C:/ paths.  Run from the source tree and use
                # a relative script name so the same invocation works for
                # both MSYS and native Unix Python.
                COMMAND "${Python3_EXECUTABLE}" "scripts/check-bootstrap-provenance.py"
                    --target "${FB_TARGET_ID}"
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                RESULT_VARIABLE _bootstrap_provenance_result
                OUTPUT_VARIABLE _bootstrap_provenance_output
                ERROR_VARIABLE _bootstrap_provenance_error
            )
            if(NOT _bootstrap_provenance_result EQUAL 0)
                message(FATAL_ERROR
                    "Bootstrap provenance verification failed for ${FB_TARGET_ID}.\n"
                    "${_bootstrap_provenance_output}${_bootstrap_provenance_error}")
            endif()

            # The checked-in generated C records the compiler version of its
            # upstream generator.  Derive a build-local copy whose public
            # version matches version.mk, after verifying the original input.
            # This preserves bootstrap provenance while preventing a release
            # archive from reporting the upstream base as its own version.
            set(_fb_prepared_bootstrap_dir
                "${CMAKE_BINARY_DIR}/bootstrap/${FB_TARGET_ID}")
            execute_process(
                COMMAND "${Python3_EXECUTABLE}" "scripts/prepare-bootstrap.py"
                    --source-dir "${FB_BOOTSTRAP_DIR}"
                    --output-dir "${_fb_prepared_bootstrap_dir}"
                    --version "${FREEBASIC_NG_VERSION}"
                    --manifest "${CMAKE_SOURCE_DIR}/bootstrap/provenance.json"
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                RESULT_VARIABLE _bootstrap_prepare_result
                OUTPUT_VARIABLE _bootstrap_prepare_output
                ERROR_VARIABLE _bootstrap_prepare_error
            )
            if(NOT _bootstrap_prepare_result EQUAL 0)
                message(FATAL_ERROR
                    "Versioned bootstrap preparation failed for ${FB_TARGET_ID}.\n"
                    "${_bootstrap_prepare_output}${_bootstrap_prepare_error}")
            endif()
            file(GLOB FB_BOOTSTRAP_SOURCES "${_fb_prepared_bootstrap_dir}/*.c")
            list(LENGTH _fb_bootstrap_input_sources _fb_bootstrap_input_count)
            list(LENGTH FB_BOOTSTRAP_SOURCES _fb_prepared_bootstrap_count)
            if(NOT _fb_bootstrap_input_count EQUAL _fb_prepared_bootstrap_count)
                message(FATAL_ERROR
                    "Versioned bootstrap preparation changed the C-source count for ${FB_TARGET_ID}.")
            endif()
            set(FB_BOOTSTRAP_MODE "bootstrap")
            message(STATUS "No fbc found, will bootstrap from verified C sources in ${FB_BOOTSTRAP_DIR}")
        else()
            message(FATAL_ERROR "Bootstrap directory exists but contains no .c files: ${FB_BOOTSTRAP_DIR}")
        endif()
    else()
        message(FATAL_ERROR
            "No fbc compiler found and no verified bootstrap sources exist for ${FB_TARGET_ID}.\n"
            "This build never substitutes another host's bootstrap sources.\n"
            "Either enable FB_USE_SYSTEM_FBC with a working fbc, or add a verified bootstrap/${FB_TARGET_ID}/ entry.")
    endif()
endif()

# Clang compatibility flags for bootstrap C sources
set(FB_BOOTSTRAP_C_FLAGS
    -fno-strict-aliasing
    -fwrapv
    -fno-ident
)

# -frounding-math is GCC-only (clang accepts but ignores it)
if(NOT FB_USING_CLANG)
    list(APPEND FB_BOOTSTRAP_C_FLAGS -frounding-math)
endif()

# -nostdinc: the bootstrap C sources redeclare everything they need,
# but on Windows/MinGW we still need system headers for the Windows API
if(NOT WIN32)
    list(APPEND FB_BOOTSTRAP_C_FLAGS -nostdinc)
endif()

set(FB_BOOTSTRAP_C_WARNINGS
    -Wall
    -Wno-unused-label
    -Wno-unused-function
    -Wno-unused-variable
    -Wno-main
    -Wfatal-errors
)

# -Wno-unused-but-set-variable: GCC-specific, clang has it since v13
if(NOT FB_USING_CLANG)
    list(APPEND FB_BOOTSTRAP_C_WARNINGS -Wno-unused-but-set-variable)
endif()

if(FB_USING_CLANG)
    list(APPEND FB_BOOTSTRAP_C_WARNINGS
        -Wno-incompatible-library-redeclaration
        -Wno-sometimes-uninitialized
    )
endif()
