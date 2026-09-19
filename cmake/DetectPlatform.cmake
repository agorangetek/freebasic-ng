# cmake/DetectPlatform.cmake
# Canonical platform detection for FreeBASIC
# Sets: FB_TARGET_OS, FB_TARGET_ARCH, FB_TARGET_ID

# --- OS Detection ---
if(WIN32)
    set(FB_TARGET_OS "win32")
elseif(APPLE)
    set(FB_TARGET_OS "darwin")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(FB_TARGET_OS "linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
    set(FB_TARGET_OS "freebsd")
elseif(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
    set(FB_TARGET_OS "openbsd")
elseif(CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
    set(FB_TARGET_OS "netbsd")
elseif(CMAKE_SYSTEM_NAME STREQUAL "DragonFly")
    set(FB_TARGET_OS "dragonfly")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Generic" AND FB_TARGET_OS)
    # Cross-compilation with explicit FB_TARGET_OS (set by toolchain file)
elseif(FB_TARGET_OS MATCHES "^(amiga|aros|morphos|amigaos4)$")
    # Already set by toolchain file
else()
    message(FATAL_ERROR "Unsupported OS: ${CMAKE_SYSTEM_NAME}")
endif()

# --- Architecture Detection ---
# CMAKE_SYSTEM_PROCESSOR is set by CMake or toolchain file
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" _arch)

if(_arch MATCHES "^(x86_64|amd64)$")
    set(FB_TARGET_ARCH "x86_64")
elseif(_arch MATCHES "^(aarch64|arm64)$")
    set(FB_TARGET_ARCH "aarch64")
elseif(_arch MATCHES "^(i[3-6]86|x86)$")
    set(FB_TARGET_ARCH "x86")
elseif(_arch MATCHES "^arm")
    set(FB_TARGET_ARCH "arm")
elseif(_arch MATCHES "^m68k$")
    set(FB_TARGET_ARCH "m68k")
elseif(_arch MATCHES "^(ppc|powerpc)$")
    set(FB_TARGET_ARCH "powerpc")
else()
    message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# --- Target ID (used for lib/ directory naming) ---
if(FB_TARGET_OS STREQUAL "win32" AND FB_TARGET_ARCH STREQUAL "x86_64")
    set(FB_TARGET_ID "win64")
elseif(FB_TARGET_OS STREQUAL "win32" AND FB_TARGET_ARCH STREQUAL "x86")
    set(FB_TARGET_ID "win32")
else()
    set(FB_TARGET_ID "${FB_TARGET_OS}-${FB_TARGET_ARCH}")
endif()

# --- CPU Family (matches FB's internal FB_CPUFAMILY_*) ---
if(FB_TARGET_ARCH STREQUAL "x86_64")
    set(FB_CPUFAMILY "x86_64")
    set(FB_64BIT TRUE)
elseif(FB_TARGET_ARCH STREQUAL "aarch64")
    set(FB_CPUFAMILY "aarch64")
    set(FB_64BIT TRUE)
elseif(FB_TARGET_ARCH STREQUAL "x86")
    set(FB_CPUFAMILY "x86")
    set(FB_64BIT FALSE)
elseif(FB_TARGET_ARCH STREQUAL "arm")
    set(FB_CPUFAMILY "arm")
    set(FB_64BIT FALSE)
elseif(FB_TARGET_ARCH STREQUAL "powerpc")
    set(FB_CPUFAMILY "powerpc")
    set(FB_64BIT FALSE)
endif()

# --- PIC requirement (non-x86 on unix-like) ---
# Darwin is excluded on purpose.  Its ABI is position-independent throughout,
# mandatory on arm64 and the default on x86_64, so the ordinary runtime already
# works inside a shared library, and fbc never asks for a pic variant there:
# hTargetNeedsPIC() in src/compiler/fbc.bas leaves Darwin out, and -pic is
# rejected for the target.  Building one would install a second copy of libfb
# plus fbrt0pic.o that nothing can link.
set(FB_NEED_PIC FALSE)
if(NOT WIN32
   AND NOT FB_TARGET_ARCH STREQUAL "x86"
   AND NOT FB_TARGET_OS STREQUAL "darwin"
   AND NOT FB_TARGET_OS MATCHES "^(amiga|aros|morphos|amigaos4)$")
    set(FB_NEED_PIC TRUE)
endif()

# --- Compiler-specific flags ---
if(CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang")
    set(FB_USING_CLANG TRUE)
else()
    set(FB_USING_CLANG FALSE)
endif()
