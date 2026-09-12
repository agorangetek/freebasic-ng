# src/rtlib/CMakeLists.txt
# FreeBASIC Runtime Library (libfb)

# --- Collect source files ---

# Common sources (platform-independent)
file(GLOB RTLIB_COMMON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Exclude files with platform-specific issues
if(APPLE)
    # profile_cycles.c uses ELF section attributes incompatible with Mach-O
    list(FILTER RTLIB_COMMON_SOURCES EXCLUDE REGEX "profile_cycles\\.c$")
endif()

# Platform-specific sources
if(WIN32)
    file(GLOB RTLIB_PLATFORM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/win32/*.c")
elseif(UNIX)
    # All unix-like systems share the unix/ directory
    file(GLOB RTLIB_UNIX_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/unix/*.c")

    # OS-specific overrides
    if(FB_TARGET_OS STREQUAL "darwin")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/darwin/*.c")
    elseif(FB_TARGET_OS STREQUAL "linux")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/linux/*.c")
    elseif(FB_TARGET_OS STREQUAL "freebsd")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/freebsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "openbsd")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/openbsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "netbsd")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/netbsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "dragonfly")
        file(GLOB RTLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/dragonfly/*.c")
    endif()

    set(RTLIB_PLATFORM_SOURCES ${RTLIB_UNIX_SOURCES} ${RTLIB_OS_SOURCES})
elseif(FB_TARGET_OS MATCHES "^(amiga|aros|morphos|amigaos4)$")
    file(GLOB RTLIB_PLATFORM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/amiga/*.c")
    # The full runtime is assembled from the common sources above plus the
    # Amiga platform hooks.  These self-contained legacy sources define a
    # competing startup, raw m68k ABI hooks, or C runtime symbols, and must
    # not be linked into libfb alongside the regular runtime.
    list(FILTER RTLIB_PLATFORM_SOURCES EXCLUDE REGEX "/(fb_amiga_rt|startup|mathbase_stub|sprintf)\\.c$")

    # gfx_amiga.c calls the classic AmigaOS graphics ABI directly.  AROS has
    # no compatible implementation yet; the M3 console-runtime preview must
    # therefore not advertise graphics support merely by compiling a stub.
    if(FB_TARGET_OS STREQUAL "aros")
        list(FILTER RTLIB_PLATFORM_SOURCES EXCLUDE REGEX "/gfx_amiga\\.c$")
    endif()
endif()

# Architecture-specific sources (x86 asm helpers, etc.)
if(FB_TARGET_ARCH STREQUAL "x86" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/x86")
    file(GLOB RTLIB_ARCH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/x86/*.s")
endif()

set(RTLIB_ALL_SOURCES ${RTLIB_COMMON_SOURCES} ${RTLIB_PLATFORM_SOURCES} ${RTLIB_ARCH_SOURCES})

# --- Static library: libfb ---
add_library(fb STATIC ${RTLIB_ALL_SOURCES})

target_include_directories(fb PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_options(fb PRIVATE
    -Wfatal-errors -O2
    -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
)

# The historical compiler-debug job also rebuilt the C runtime with these
# flags.  They are intentionally not applied to fbc's generated C: DEBUG is
# a field name in its self-hosted output.
set(FB_RT_DEBUG_C_FLAGS)
set(FB_RT_DEBUG_C_DEFINITIONS)
set(FB_RT_DEBUG_C_DEFINE_FLAGS)
if(FB_COMPILER_DEBUG)
    # Release presets add -DNDEBUG.  Travis did not, and DEBUG assertions
    # would otherwise disappear while their variables still compile in.
    list(APPEND FB_RT_DEBUG_C_FLAGS -g -UNDEBUG -Werror)
    list(APPEND FB_RT_DEBUG_C_DEFINITIONS DEBUG)
    list(APPEND FB_RT_DEBUG_C_DEFINE_FLAGS -DDEBUG)
endif()
target_compile_options(fb PRIVATE ${FB_RT_DEBUG_C_FLAGS})
target_compile_definitions(fb PRIVATE ${FB_RT_DEBUG_C_DEFINITIONS})

target_compile_definitions(fb PRIVATE
    $<$<PLATFORM_ID:Darwin>:DISABLE_GPM>
    $<$<PLATFORM_ID:Darwin>:DISABLE_FFI>
)

# Disable optional features that require extra dependencies
# Users can override these with -DFB_DISABLE_X11=OFF etc.
option(FB_DISABLE_X11 "Build without X11 support" OFF)
option(FB_DISABLE_GPM "Build without GPM mouse support" OFF)
option(FB_DISABLE_FFI "Build without libffi (disables ThreadCall)" OFF)
option(FB_DISABLE_OPENGL "Build without OpenGL support" OFF)

if(FB_TARGET_OS STREQUAL "darwin")
    # Darwin defaults: no GPM, no FFI, no X11 unless XQuartz
    set(FB_DISABLE_GPM ON)
    set(FB_DISABLE_FFI ON)
    option(FB_ENABLE_XQUARTZ "Build with XQuartz X11 support" OFF)
    if(NOT FB_ENABLE_XQUARTZ)
        set(FB_DISABLE_X11 ON)
    endif()
endif()

if(FB_DISABLE_X11)
    target_compile_definitions(fb PRIVATE DISABLE_X11)
endif()
if(FB_DISABLE_GPM)
    target_compile_definitions(fb PRIVATE DISABLE_GPM)
endif()
if(FB_DISABLE_FFI)
    target_compile_definitions(fb PRIVATE DISABLE_FFI)
endif()
if(FB_DISABLE_OPENGL)
    target_compile_definitions(fb PRIVATE DISABLE_OPENGL)
endif()

# --- Threadsafe variant: libfbmt ---
if(NOT WIN32 OR NOT FB_TARGET_OS STREQUAL "dos")
    add_library(fbmt STATIC ${RTLIB_ALL_SOURCES})
    target_include_directories(fbmt PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    target_compile_options(fbmt PRIVATE
        -Wfatal-errors -O2
        -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
        -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
    )
    target_compile_options(fbmt PRIVATE ${FB_RT_DEBUG_C_FLAGS})
    target_compile_definitions(fbmt PRIVATE ${FB_RT_DEBUG_C_DEFINITIONS})
    target_compile_definitions(fbmt PRIVATE ENABLE_MT)
    # Copy the same DISABLE_ defines
    if(FB_DISABLE_X11)
        target_compile_definitions(fbmt PRIVATE DISABLE_X11)
    endif()
    if(FB_DISABLE_GPM)
        target_compile_definitions(fbmt PRIVATE DISABLE_GPM)
    endif()
    if(FB_DISABLE_FFI)
        target_compile_definitions(fbmt PRIVATE DISABLE_FFI)
    endif()
    if(FB_DISABLE_OPENGL)
        target_compile_definitions(fbmt PRIVATE DISABLE_OPENGL)
    endif()
endif()

# --- PIC variants for non-x86 unix ---
if(FB_NEED_PIC)
    add_library(fbpic STATIC ${RTLIB_ALL_SOURCES})
    target_include_directories(fbpic PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
    target_compile_options(fbpic PRIVATE
        -fPIC -Wfatal-errors -O2
        -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
        -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
    )
    target_compile_options(fbpic PRIVATE ${FB_RT_DEBUG_C_FLAGS})
    target_compile_definitions(fbpic PRIVATE ${FB_RT_DEBUG_C_DEFINITIONS})
    if(FB_DISABLE_X11)
        target_compile_definitions(fbpic PRIVATE DISABLE_X11)
    endif()
    if(FB_DISABLE_GPM)
        target_compile_definitions(fbpic PRIVATE DISABLE_GPM)
    endif()
    if(FB_DISABLE_FFI)
        target_compile_definitions(fbpic PRIVATE DISABLE_FFI)
    endif()
    if(FB_DISABLE_OPENGL)
        target_compile_definitions(fbpic PRIVATE DISABLE_OPENGL)
    endif()
endif()

# --- fbrt0.o (runtime startup object) ---
# Amiga targets use clib2/newlib startup, not fbrt0
if(NOT FB_TARGET_OS MATCHES "^(amiga|aros|morphos|amigaos4)$")
# We need the raw .o file, not a .a archive. Compile it directly.
set(FBRT0_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/static/fbrt0.c")
# fbc has always named its runtime startup object fbrt0.o, including on
# MinGW.  Do not inherit CMake's .obj default there: the installed compiler
# resolves the historic .o name at user compile time.
set(FBRT0_OBJ "${CMAKE_CURRENT_BINARY_DIR}/fbrt0.o")

add_custom_command(
    OUTPUT "${FBRT0_OBJ}"
    COMMAND ${CMAKE_C_COMPILER} ${FB_RT_DEBUG_C_FLAGS} ${FB_RT_DEBUG_C_DEFINE_FLAGS}
        -c -I "${CMAKE_CURRENT_SOURCE_DIR}" -o "${FBRT0_OBJ}" "${FBRT0_SOURCE}"
    COMMAND_EXPAND_LISTS
    DEPENDS "${FBRT0_SOURCE}"
    COMMENT "Compiling fbrt0.o"
    VERBATIM
)
add_custom_target(fbrt0 ALL DEPENDS "${FBRT0_OBJ}")

if(FB_NEED_PIC)
    set(FBRT0PIC_OBJ "${CMAKE_CURRENT_BINARY_DIR}/fbrt0pic.o")
    add_custom_command(
        OUTPUT "${FBRT0PIC_OBJ}"
        COMMAND ${CMAKE_C_COMPILER} ${FB_RT_DEBUG_C_FLAGS} ${FB_RT_DEBUG_C_DEFINE_FLAGS}
            -c -fPIC -I "${CMAKE_CURRENT_SOURCE_DIR}" -o "${FBRT0PIC_OBJ}" "${FBRT0_SOURCE}"
        DEPENDS "${FBRT0_SOURCE}"
        COMMENT "Compiling fbrt0pic.o"
        VERBATIM
    )
    add_custom_target(fbrt0pic ALL DEPENDS "${FBRT0PIC_OBJ}")
endif()
endif() # not amiga

# --- Installation ---
install(TARGETS fb ARCHIVE DESTINATION "${FB_INSTALL_LIBDIR}")
# fbc passes this supplemental linker script to GNU ld on non-Darwin
# targets.  It is part of the compiler runtime layout, rather than a build
# input, so a staged installation without it cannot compile a program.
install(FILES "${CMAKE_SOURCE_DIR}/lib/fbextra.x" DESTINATION "${FB_INSTALL_LIBDIR}")
if(DEFINED FBRT0_OBJ)
    install(FILES "${FBRT0_OBJ}" DESTINATION "${FB_INSTALL_LIBDIR}" RENAME "fbrt0.o")
endif()

if(TARGET fbmt)
    install(TARGETS fbmt ARCHIVE DESTINATION "${FB_INSTALL_LIBDIR}")
endif()
if(FB_NEED_PIC)
    install(TARGETS fbpic ARCHIVE DESTINATION "${FB_INSTALL_LIBDIR}")
    if(DEFINED FBRT0PIC_OBJ)
        install(FILES "${FBRT0PIC_OBJ}" DESTINATION "${FB_INSTALL_LIBDIR}" RENAME "fbrt0pic.o")
    endif()
endif()
