# CMake toolchain file for AmigaOS 3.x (m68k).
#
# Set AMIGA_GCC_ROOT to an immutable amiga-gcc prefix (for example /opt/amiga
# from the pinned CI container).  Homebrew discovery is retained solely as a
# local-development fallback.
if(NOT AMIGA_GCC_ROOT AND DEFINED ENV{AMIGA_GCC_ROOT} AND
   NOT "$ENV{AMIGA_GCC_ROOT}" STREQUAL "")
    set(AMIGA_GCC_ROOT "$ENV{AMIGA_GCC_ROOT}")
endif()

if(NOT AMIGA_GCC_ROOT)
    find_program(_amiga_brew NAMES brew)
    if(_amiga_brew)
        execute_process(
            COMMAND "${_amiga_brew}" --prefix amiga-gcc
            RESULT_VARIABLE _amiga_brew_result
            OUTPUT_VARIABLE AMIGA_GCC_ROOT
            OUTPUT_STRIP_TRAILING_WHITESPACE)
    endif()
endif()

if(NOT AMIGA_GCC_ROOT OR NOT IS_DIRECTORY "${AMIGA_GCC_ROOT}")
    message(FATAL_ERROR
        "Set AMIGA_GCC_ROOT to an amiga-gcc prefix; Homebrew fallback was unavailable")
endif()

cmake_path(ABSOLUTE_PATH AMIGA_GCC_ROOT NORMALIZE OUTPUT_VARIABLE AMIGA_GCC_ROOT)
set(AMIGA_GCC_ROOT "${AMIGA_GCC_ROOT}" CACHE PATH
    "amiga-gcc distribution prefix" FORCE)

# CMake evaluates the toolchain file again for compiler ABI try-compiles.
# Preserve an explicitly supplied prefix in that nested configuration too.
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES AMIGA_GCC_ROOT)

set(_amiga_sysroot "${AMIGA_GCC_ROOT}/m68k-amigaos")

foreach(_amiga_tool IN ITEMS m68k-amigaos-gcc m68k-amigaos-ar m68k-amigaos-ranlib)
    if(NOT EXISTS "${AMIGA_GCC_ROOT}/bin/${_amiga_tool}")
        message(FATAL_ERROR
            "amiga-gcc prefix lacks bin/${_amiga_tool}: ${AMIGA_GCC_ROOT}")
    endif()
endforeach()
if(NOT IS_DIRECTORY "${_amiga_sysroot}/lib" OR
   NOT IS_DIRECTORY "${_amiga_sysroot}/sys-include" OR
   NOT IS_DIRECTORY "${_amiga_sysroot}/ndk-include")
    message(FATAL_ERROR "Incomplete AmigaOS/m68k sysroot: ${_amiga_sysroot}")
endif()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR m68k)
set(CMAKE_C_COMPILER "${AMIGA_GCC_ROOT}/bin/m68k-amigaos-gcc")
set(CMAKE_AR "${AMIGA_GCC_ROOT}/bin/m68k-amigaos-ar")
set(CMAKE_RANLIB "${AMIGA_GCC_ROOT}/bin/m68k-amigaos-ranlib")

set(CMAKE_C_FLAGS_INIT "-m68020 -msoft-float -fomit-frame-pointer -fno-common -isystem ${_amiga_sysroot}/sys-include -isystem ${_amiga_sysroot}/ndk-include")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-B${_amiga_sysroot}/lib -L${_amiga_sysroot}/lib")
set(CMAKE_FIND_ROOT_PATH "${_amiga_sysroot}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(FB_TARGET_OS "amiga" CACHE STRING "" FORCE)
set(FB_TARGET_ARCH "m68k" CACHE STRING "" FORCE)
