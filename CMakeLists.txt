cmake_minimum_required(VERSION 3.20)

# version.mk is the source of truth for the compiler version.  Keeping CMake
# derived from it prevents the build and the legacy packaging metadata from
# silently drifting apart.
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/version.mk" _fb_version_line
    REGEX "^FBVERSION[ \t]*:=[ \t]*[0-9]+\\.[0-9]+\\.[0-9]+$")
if(NOT _fb_version_line)
    message(FATAL_ERROR "Could not read a semantic FBVERSION from version.mk")
endif()
string(REGEX REPLACE "^FBVERSION[ \t]*:=[ \t]*([0-9]+\\.[0-9]+\\.[0-9]+)$"
    "\\1" FREEBASIC_NG_VERSION "${_fb_version_line}")

project(FreeBASICNG VERSION ${FREEBASIC_NG_VERSION} LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# FreeBASIC-NG requires GCC or Clang (MinGW on Windows)
if(MSVC)
    message(FATAL_ERROR
        "MSVC is not supported. Use MinGW-w64 on Windows.\n"
        "Configure with: cmake -G \"MinGW Makefiles\" or use MSYS2.")
endif()

# Options
option(FB_STANDALONE "Build as self-contained installation" ON)
option(FB_BUILD_GFXLIB "Build the graphics library" ON)
option(FB_BUILD_COMPILER "Build the fbc compiler" ON)
option(FB_BUILD_TESTS "Build tests" OFF)
option(FB_USE_SYSTEM_FBC "Use an existing fbc instead of the bundled bootstrap sources" OFF)

# Platform detection (sets FB_TARGET_OS, FB_TARGET_ARCH, FB_TARGET_ID)
include(cmake/DetectPlatform.cmake)

# Bootstrap logic (determines how to build fbc)
if(FB_BUILD_COMPILER)
    include(cmake/Bootstrap.cmake)
endif()

# Install paths (needed by subdirectories)
include(cmake/Install.cmake)

# Runtime library (libfb)
add_subdirectory(src/rtlib)

# Graphics library (libfbgfx) - optional
if(FB_BUILD_GFXLIB)
    add_subdirectory(src/gfxlib2)
endif()

# Compiler (fbc)
if(FB_BUILD_COMPILER)
    add_subdirectory(src/compiler)
endif()

# Summary
message(STATUS "")
message(STATUS "FreeBASIC-NG ${PROJECT_VERSION}")
message(STATUS "  Target:     ${FB_TARGET_ID}")
message(STATUS "  OS:         ${FB_TARGET_OS}")
message(STATUS "  Arch:       ${FB_TARGET_ARCH}")
message(STATUS "  Bootstrap:  ${FB_BOOTSTRAP_MODE}")
message(STATUS "  Standalone: ${FB_STANDALONE}")
message(STATUS "  GfxLib:     ${FB_BUILD_GFXLIB}")
message(STATUS "")
