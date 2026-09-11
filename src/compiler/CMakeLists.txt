# src/compiler/CMakeLists.txt
# FreeBASIC Compiler (fbc)
#
# Two build modes:
#   1. Bootstrap: compile pre-generated .c files from bootstrap/ directory
#   2. Native: use an existing fbc to compile .bas sources

include(${CMAKE_SOURCE_DIR}/cmake/FixComputedGoto.cmake)

# --- Bootstrap mode: build fbc from pre-generated C sources ---
if(FB_BOOTSTRAP_MODE STREQUAL "bootstrap")

    # Fix computed goto for clang before compiling
    if(FB_USING_CLANG)
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        # CMake supplies native C:/ paths on Windows, while the CLANGARM64
        # Python interpreter is an MSYS program and only accepts POSIX paths.
        # Relative paths from the build directory are understood by both.
        file(REAL_PATH "${CMAKE_CURRENT_BINARY_DIR}" _fix_working_directory)
        file(REAL_PATH "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
            _fix_computed_goto_script_absolute)
        file(RELATIVE_PATH _fix_computed_goto_script
            "${_fix_working_directory}"
            "${_fix_computed_goto_script_absolute}")
        set(_fixed_sources "")
        foreach(_src ${FB_BOOTSTRAP_SOURCES})
            get_filename_component(_name ${_src} NAME)
            set(_fixed "${CMAKE_CURRENT_BINARY_DIR}/fixed/${_name}")
            add_custom_command(
                OUTPUT "${_fixed}"
                COMMAND ${CMAKE_COMMAND} -E copy "${_src}" "${_fixed}"
                COMMAND ${Python3_EXECUTABLE} "${_fix_computed_goto_script}" "fixed/${_name}"
                WORKING_DIRECTORY "${_fix_working_directory}"
                DEPENDS "${_src}" "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
                COMMENT "Preparing ${_name} for clang"
                VERBATIM
            )
            list(APPEND _fixed_sources "${_fixed}")
        endforeach()
        set(_compile_sources ${_fixed_sources})
    else()
        set(_compile_sources ${FB_BOOTSTRAP_SOURCES})
    endif()

    add_executable(fbc ${_compile_sources})

    target_compile_options(fbc PRIVATE
        -nostdinc
        ${FB_BOOTSTRAP_C_FLAGS}
        ${FB_BOOTSTRAP_C_WARNINGS}
        -O2
    )

    # Link against rtlib
    target_link_libraries(fbc PRIVATE fb)

    # Platform link libraries
    if(APPLE)
        target_link_libraries(fbc PRIVATE "-lncurses" "-lm" "-lpthread")
    elseif(UNIX)
        target_link_libraries(fbc PRIVATE ncurses m pthread)
    elseif(WIN32)
        target_link_libraries(fbc PRIVATE advapi32 user32 kernel32)
    endif()

    # Link fbrt0
    set(FBRT0_OBJ "${CMAKE_BINARY_DIR}/src/rtlib/fbrt0.o")
    target_link_options(fbc PRIVATE "${FBRT0_OBJ}")
    add_dependencies(fbc fbrt0)

# --- Native mode: use existing fbc to compile .bas sources ---
else()

    file(GLOB FBC_BAS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.bas")
    file(GLOB FBC_BI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.bi")

    # Generate .c files from .bas using the existing fbc
    set(_gen_c_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
    file(MAKE_DIRECTORY "${_gen_c_dir}")

    set(_generated_c_files "")
    set(_fbc_flags -gen gcc -r -m fbc -i "${CMAKE_SOURCE_DIR}/inc" -target ${FB_TARGET_ID})
    if(FB_STANDALONE)
        list(APPEND _fbc_flags -d ENABLE_STANDALONE)
    endif()

    # Single invocation to compile all .bas to .c
    # fbc compiles all at once when given -m fbc
    set(_gen_stamp "${_gen_c_dir}/.generated")
    add_custom_command(
        OUTPUT "${_gen_stamp}"
        COMMAND ${FBC_EXECUTABLE} ${_fbc_flags} ${FBC_BAS_SOURCES}
        COMMAND ${CMAKE_COMMAND} -E rename_if_different # move .c files to gen dir
        COMMAND ${CMAKE_COMMAND} -E touch "${_gen_stamp}"
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        DEPENDS ${FBC_BAS_SOURCES} ${FBC_BI_SOURCES}
        COMMENT "Compiling FreeBASIC sources with fbc"
        VERBATIM
    )

    # Collect the generated .c files
    # Since we can't know them at configure time, use a glob at build time
    file(GLOB _existing_gen_c "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

    # For native builds, we compile the .c files that fbc generates
    # The .c files are placed next to the .bas files by fbc -r
    add_custom_target(fbc_generate DEPENDS "${_gen_stamp}")

    add_executable(fbc ${_existing_gen_c})
    add_dependencies(fbc fbc_generate)

    # Fix computed goto for clang
    if(FB_USING_CLANG)
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        file(REAL_PATH "${CMAKE_CURRENT_BINARY_DIR}" _fix_working_directory)
        file(REAL_PATH "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
            _fix_computed_goto_script_absolute)
        file(RELATIVE_PATH _fix_computed_goto_script
            "${_fix_working_directory}"
            "${_fix_computed_goto_script_absolute}")
        set(_existing_gen_c_relative "")
        foreach(_src ${_existing_gen_c})
            file(REAL_PATH "${_src}" _real_src)
            file(RELATIVE_PATH _relative_src "${_fix_working_directory}" "${_real_src}")
            list(APPEND _existing_gen_c_relative "${_relative_src}")
        endforeach()
        add_custom_command(
            TARGET fbc PRE_BUILD
            COMMAND ${Python3_EXECUTABLE} "${_fix_computed_goto_script}"
                    ${_existing_gen_c_relative}
            WORKING_DIRECTORY "${_fix_working_directory}"
            COMMENT "Fixing computed goto for clang"
            VERBATIM
        )
    endif()

    target_compile_options(fbc PRIVATE
        -nostdinc
        ${FB_BOOTSTRAP_C_FLAGS}
        ${FB_BOOTSTRAP_C_WARNINGS}
        -O2
    )

    target_link_libraries(fbc PRIVATE fb)

    if(APPLE)
        target_link_libraries(fbc PRIVATE "-lncurses" "-lm" "-lpthread")
    elseif(UNIX)
        target_link_libraries(fbc PRIVATE ncurses m pthread)
    elseif(WIN32)
        target_link_libraries(fbc PRIVATE advapi32 user32 kernel32)
    endif()

    set(FBRT0_OBJ "${CMAKE_BINARY_DIR}/src/rtlib/fbrt0.o")
    target_link_options(fbc PRIVATE "${FBRT0_OBJ}")
    add_dependencies(fbc fbrt0)

endif()

# --- Installation ---
install(TARGETS fbc RUNTIME DESTINATION "${FB_INSTALL_BINDIR}")
