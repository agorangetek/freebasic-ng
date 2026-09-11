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
    # Check for bootstrap C sources
    set(_bootstrap_dir "${CMAKE_SOURCE_DIR}/bootstrap/${FB_TARGET_ID}")
    if(NOT EXISTS "${_bootstrap_dir}")
        # Cross-compatible fallbacks: the generated C is platform-independent
        if(FB_TARGET_OS STREQUAL "darwin" AND FB_TARGET_ARCH STREQUAL "aarch64")
            set(_bootstrap_dir "${CMAKE_SOURCE_DIR}/bootstrap/linux-aarch64")
        elseif(FB_TARGET_OS STREQUAL "darwin" AND FB_TARGET_ARCH STREQUAL "x86_64")
            set(_bootstrap_dir "${CMAKE_SOURCE_DIR}/bootstrap/linux-x86_64")
        endif()
    endif()

    if(EXISTS "${_bootstrap_dir}")
        file(GLOB FB_BOOTSTRAP_SOURCES "${_bootstrap_dir}/*.c")
        if(FB_BOOTSTRAP_SOURCES)
            set(FB_BOOTSTRAP_MODE "bootstrap")
            message(STATUS "No fbc found, will bootstrap from C sources in ${_bootstrap_dir}")
        else()
            message(FATAL_ERROR "Bootstrap directory exists but contains no .c files: ${_bootstrap_dir}")
        endif()
    else()
        message(FATAL_ERROR
            "No fbc compiler found and no bootstrap sources available for ${FB_TARGET_ID}.\n"
            "Either install fbc, or provide bootstrap C sources in bootstrap/${FB_TARGET_ID}/")
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
