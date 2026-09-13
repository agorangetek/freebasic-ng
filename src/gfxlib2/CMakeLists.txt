# src/gfxlib2/CMakeLists.txt
# FreeBASIC Graphics Library (libfbgfx)

# --- Collect source files ---
file(GLOB GFXLIB_COMMON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

if(WIN32)
    file(GLOB GFXLIB_PLATFORM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/win32/*.c")
elseif(UNIX)
    # Base unix source (always needed)
    set(GFXLIB_UNIX_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_unix.c")

    # X11 sources (only if X11 is available)
    if(NOT FB_DISABLE_X11)
        find_package(X11)
        if(X11_FOUND)
            list(APPEND GFXLIB_UNIX_SOURCES
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_x11.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_x11_icon_stub.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_driver_x11.c"
                "${CMAKE_CURRENT_SOURCE_DIR}/unix/gfx_driver_opengl_x11.c"
            )
        else()
            set(FB_DISABLE_X11 ON)
        endif()
    endif()

    # OS-specific overrides
    if(FB_TARGET_OS STREQUAL "linux")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/linux/*.c")
    elseif(FB_TARGET_OS STREQUAL "freebsd")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/freebsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "openbsd")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/openbsd/*.c")
    elseif(FB_TARGET_OS STREQUAL "dragonfly")
        file(GLOB GFXLIB_OS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/dragonfly/*.c")
    endif()

    set(GFXLIB_PLATFORM_SOURCES ${GFXLIB_UNIX_SOURCES} ${GFXLIB_OS_SOURCES})
endif()

# x86 asm sources
if(FB_TARGET_ARCH STREQUAL "x86" AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/x86")
    file(GLOB GFXLIB_ARCH_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/x86/*.s")
    # The x86 MMX sources include fb_gfx_mmx.h and were historically built
    # with GCC's preprocessed-assembly mode.
    set_source_files_properties(${GFXLIB_ARCH_SOURCES}
        PROPERTIES COMPILE_OPTIONS "-x;assembler-with-cpp")
endif()

set(GFXLIB_ALL_SOURCES ${GFXLIB_COMMON_SOURCES} ${GFXLIB_PLATFORM_SOURCES} ${GFXLIB_ARCH_SOURCES})

# --- libfbgfx ---
add_library(fbgfx STATIC ${GFXLIB_ALL_SOURCES})

target_include_directories(fbgfx PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "$<$<PLATFORM_ID:Darwin,Linux,FreeBSD,OpenBSD,NetBSD>:${CMAKE_CURRENT_SOURCE_DIR}/unix>"
    "$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/win32>"
    "${CMAKE_SOURCE_DIR}/src/rtlib"
)

target_compile_options(fbgfx PRIVATE
    -Wfatal-errors -O2
    -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
)
if(FB_COMPILER_DEBUG)
    target_compile_options(fbgfx PRIVATE -g -UNDEBUG -Werror)
    target_compile_definitions(fbgfx PRIVATE DEBUG)
endif()

# Feature flags (inherited from rtlib settings)
if(FB_DISABLE_X11)
    target_compile_definitions(fbgfx PRIVATE DISABLE_X11)
endif()
if(FB_DISABLE_OPENGL)
    target_compile_definitions(fbgfx PRIVATE DISABLE_OPENGL)
endif()

# X11 include dirs (if found above)
if(UNIX AND NOT FB_DISABLE_X11 AND X11_FOUND)
    target_include_directories(fbgfx PRIVATE ${X11_INCLUDE_DIR})
endif()

# --- Threadsafe variant ---
add_library(fbgfxmt STATIC ${GFXLIB_ALL_SOURCES})
target_include_directories(fbgfxmt PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "$<$<PLATFORM_ID:Darwin,Linux,FreeBSD,OpenBSD,NetBSD>:${CMAKE_CURRENT_SOURCE_DIR}/unix>"
    "$<$<PLATFORM_ID:Windows>:${CMAKE_CURRENT_SOURCE_DIR}/win32>"
    "${CMAKE_SOURCE_DIR}/src/rtlib"
)
target_compile_options(fbgfxmt PRIVATE
    -Wfatal-errors -O2
    -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables
    -Wall -Wextra -Wno-unused-parameter -Werror-implicit-function-declaration
)
if(FB_COMPILER_DEBUG)
    target_compile_options(fbgfxmt PRIVATE -g -UNDEBUG -Werror)
    target_compile_definitions(fbgfxmt PRIVATE DEBUG)
endif()
target_compile_definitions(fbgfxmt PRIVATE ENABLE_MT)
if(FB_DISABLE_X11)
    target_compile_definitions(fbgfxmt PRIVATE DISABLE_X11)
endif()
if(FB_DISABLE_OPENGL)
    target_compile_definitions(fbgfxmt PRIVATE DISABLE_OPENGL)
endif()

# --- Installation ---
install(TARGETS fbgfx fbgfxmt ARCHIVE DESTINATION "${FB_INSTALL_LIBDIR}")
