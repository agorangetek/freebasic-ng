# cmake/Bootstrap.cmake
# Handles building fbc from an installed compiler or a verified minimal seed.
#
# Bootstrap modes:
#   "native"    - Use an existing fbc to compile .bas sources directly
#   "seed"      - Download a provenance-verified fbc seed, then compile .bas
#                 sources directly

# A source build must not change merely because another fbc happens to be in
# PATH. Developers can explicitly opt in to a local compiler; otherwise the
# target-specific seed manifest selects a fixed, checksum-verified compiler.
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
    if(NOT FB_DOWNLOAD_BOOTSTRAP_SEED)
        message(FATAL_ERROR
            "No fbc compiler found and bootstrap-seed download is disabled.\n"
            "Enable FB_USE_SYSTEM_FBC with a working fbc, or enable FB_DOWNLOAD_BOOTSTRAP_SEED.")
    endif()

    find_package(Python3 COMPONENTS Interpreter REQUIRED)
    get_filename_component(_fb_seed_cache "${FB_BOOTSTRAP_SEED_CACHE}" ABSOLUTE
        BASE_DIR "${CMAKE_BINARY_DIR}")
    if(WIN32)
        # MSYS Python expects POSIX paths while native CMake passes C:/ paths.
        # Relative paths from the build directory are understood by both.
        file(RELATIVE_PATH _fb_seed_script "${CMAKE_BINARY_DIR}"
            "${CMAKE_SOURCE_DIR}/scripts/fetch-bootstrap-seed.py")
        file(RELATIVE_PATH _fb_seed_manifest "${CMAKE_BINARY_DIR}"
            "${CMAKE_SOURCE_DIR}/bootstrap/seed-provenance.json")
        file(RELATIVE_PATH _fb_seed_cache_argument "${CMAKE_BINARY_DIR}"
            "${_fb_seed_cache}")
    else()
        # Keep native absolute paths on Unix. macOS commonly resolves /tmp via
        # /private/tmp, so a relative path computed from the logical path can
        # point at a different directory.
        set(_fb_seed_script "${CMAKE_SOURCE_DIR}/scripts/fetch-bootstrap-seed.py")
        set(_fb_seed_manifest "${CMAKE_SOURCE_DIR}/bootstrap/seed-provenance.json")
        set(_fb_seed_cache_argument "${_fb_seed_cache}")
    endif()
    execute_process(
        COMMAND "${Python3_EXECUTABLE}" "${_fb_seed_script}"
            --manifest "${_fb_seed_manifest}"
            --target "${FB_TARGET_ID}"
            --cache-dir "${_fb_seed_cache_argument}"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        RESULT_VARIABLE _fb_seed_result
        OUTPUT_VARIABLE _fb_seed_output
        ERROR_VARIABLE _fb_seed_error
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(NOT _fb_seed_result EQUAL 0)
        message(FATAL_ERROR
            "Bootstrap seed preparation failed for ${FB_TARGET_ID}.\n"
            "${_fb_seed_output}${_fb_seed_error}")
    endif()
    get_filename_component(FBC_EXECUTABLE "${_fb_seed_output}" ABSOLUTE
        BASE_DIR "${CMAKE_BINARY_DIR}")
    execute_process(
        COMMAND "${FBC_EXECUTABLE}" --version
        OUTPUT_VARIABLE _fb_seed_version
        ERROR_VARIABLE _fb_seed_version_error
        RESULT_VARIABLE _fb_seed_version_result
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(NOT _fb_seed_version_result EQUAL 0)
        message(FATAL_ERROR
            "Verified bootstrap seed cannot execute for ${FB_TARGET_ID}.\n"
            "${_fb_seed_version}${_fb_seed_version_error}")
    endif()
    set(FB_BOOTSTRAP_MODE "seed")
    message(STATUS "No fbc found, using verified ${FB_TARGET_ID} bootstrap seed")
    message(STATUS "  ${_fb_seed_version}")
endif()

# Clang compatibility flags for generated compiler C sources
set(FB_BOOTSTRAP_C_FLAGS
    -fno-strict-aliasing
    -fwrapv
    -fno-ident
)

# -frounding-math is GCC-only (clang accepts but ignores it)
if(NOT FB_USING_CLANG)
    list(APPEND FB_BOOTSTRAP_C_FLAGS -frounding-math)
endif()

# -nostdinc: generated compiler C sources redeclare everything they need,
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
