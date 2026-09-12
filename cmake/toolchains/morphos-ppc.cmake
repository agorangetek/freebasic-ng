# CMake toolchain file for MorphOS PowerPC.
#
# Set MORPHOS_GCC_ROOT to the immutable ppc-morphos SDK prefix (for example
# /opt/ppc-morphos from the pinned crosstools container).
if(NOT MORPHOS_GCC_ROOT AND DEFINED ENV{MORPHOS_GCC_ROOT} AND
   NOT "$ENV{MORPHOS_GCC_ROOT}" STREQUAL "")
    set(MORPHOS_GCC_ROOT "$ENV{MORPHOS_GCC_ROOT}")
endif()

if(NOT MORPHOS_GCC_ROOT OR NOT IS_DIRECTORY "${MORPHOS_GCC_ROOT}")
    message(FATAL_ERROR "Set MORPHOS_GCC_ROOT to a ppc-morphos SDK prefix")
endif()

cmake_path(ABSOLUTE_PATH MORPHOS_GCC_ROOT NORMALIZE OUTPUT_VARIABLE MORPHOS_GCC_ROOT)
set(MORPHOS_GCC_ROOT "${MORPHOS_GCC_ROOT}" CACHE PATH
    "ppc-morphos SDK prefix" FORCE)

# Preserve the supplied SDK prefix in compiler ABI try-compiles too.
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES MORPHOS_GCC_ROOT)

foreach(_morphos_tool IN ITEMS ppc-morphos-gcc ppc-morphos-ar ppc-morphos-ranlib)
    if(NOT EXISTS "${MORPHOS_GCC_ROOT}/bin/${_morphos_tool}")
        message(FATAL_ERROR
            "MorphOS SDK lacks bin/${_morphos_tool}: ${MORPHOS_GCC_ROOT}")
    endif()
endforeach()
if(NOT IS_DIRECTORY "${MORPHOS_GCC_ROOT}/os-include" OR
   NOT IS_DIRECTORY "${MORPHOS_GCC_ROOT}/lib")
    message(FATAL_ERROR "Incomplete MorphOS PowerPC SDK: ${MORPHOS_GCC_ROOT}")
endif()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR powerpc)
set(CMAKE_C_COMPILER "${MORPHOS_GCC_ROOT}/bin/ppc-morphos-gcc")
set(CMAKE_AR "${MORPHOS_GCC_ROOT}/bin/ppc-morphos-ar")
set(CMAKE_RANLIB "${MORPHOS_GCC_ROOT}/bin/ppc-morphos-ranlib")

# FreeBASIC's Amiga graphics hooks call native MorphOS libraries.  The SDK
# rejects a mixture of those calls and ixemul's ABI, so both compilation and
# later program links must opt into the native C runtime explicitly.
set(CMAKE_C_FLAGS_INIT "-noixemul")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-noixemul")

# The compiler driver supplies MorphOS' SDK include and library paths.
set(CMAKE_FIND_ROOT_PATH "${MORPHOS_GCC_ROOT}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(FB_TARGET_OS "morphos" CACHE STRING "" FORCE)
set(FB_TARGET_ARCH "powerpc" CACHE STRING "" FORCE)
