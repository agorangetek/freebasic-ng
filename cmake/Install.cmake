# cmake/Install.cmake
# Installation rules for FreeBASIC-NG

include(GNUInstallDirs)

if(FB_STANDALONE)
    # Standalone: everything under one prefix
    set(FB_INSTALL_BINDIR "bin")
    set(FB_INSTALL_LIBDIR "lib/${FB_TARGET_ID}")
    set(FB_INSTALL_INCDIR "inc")
else()
    # System install (Linux distro style)
    set(FB_INSTALL_BINDIR "${CMAKE_INSTALL_BINDIR}")
    set(FB_INSTALL_LIBDIR "${CMAKE_INSTALL_LIBDIR}/freebasic/${FB_TARGET_ID}")
    set(FB_INSTALL_INCDIR "${CMAKE_INSTALL_INCLUDEDIR}/freebasic")
endif()

# Install FB include files
if(EXISTS "${CMAKE_SOURCE_DIR}/inc")
    install(DIRECTORY inc/ DESTINATION "${FB_INSTALL_INCDIR}")
endif()
