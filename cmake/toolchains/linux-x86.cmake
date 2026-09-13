# Build a runnable 32-bit Linux/x86 compiler on an x86_64 Linux host.
#
# The seed fbc remains a native x86_64 executable; it emits Linux/x86 sources
# for the final compiler, which GCC assembles or compiles with -m32.
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS_INIT "-m32")
set(CMAKE_ASM_FLAGS_INIT "-m32")
set(CMAKE_EXE_LINKER_FLAGS_INIT "-m32")

# Keep the seed compiler and build tools on the x86_64 build host.  Libraries
# and headers are selected by GCC's multilib support rather than a sysroot.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE NEVER)
