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

    file(GLOB FBC_BAS_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.bas")
    file(GLOB FBC_BI_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.bi")

    # Generate backend sources from a build-tree copy of the compiler sources.
    # fbc writes -r output next to its input files; running it on the source
    # tree would leave generated files behind and, more importantly, the old
    # code globbed those files at configure time before they existed.  The
    # compiler source file names are unique, so their known BAS inputs also
    # give CMake the complete output set up front.
    set(_native_backend "${FB_NATIVE_COMPILER_BACKEND}")
    set(_native_output_extension "c")
    if(_native_backend STREQUAL "gas64")
        enable_language(ASM)
        set(_native_output_extension "asm")
    endif()
    set(_native_source_dir "${CMAKE_CURRENT_BINARY_DIR}/native-source")
    set(_native_copied_inputs "")
    set(_native_copied_bas_sources "")
    set(_generated_backend_files "")
    foreach(_source IN LISTS FBC_BAS_SOURCES FBC_BI_SOURCES)
        get_filename_component(_name "${_source}" NAME)
        set(_copy "${_native_source_dir}/${_name}")
        add_custom_command(
            OUTPUT "${_copy}"
            COMMAND ${CMAKE_COMMAND} -E make_directory "${_native_source_dir}"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${_source}" "${_copy}"
            DEPENDS "${_source}"
            COMMENT "Preparing ${_name} for native compiler build"
            VERBATIM
        )
        list(APPEND _native_copied_inputs "${_copy}")
        if(_source MATCHES "\\.bas$")
            list(APPEND _native_copied_bas_sources "${_copy}")
            get_filename_component(_base "${_source}" NAME_WE)
            list(APPEND _generated_backend_files
                "${_native_source_dir}/${_base}.${_native_output_extension}")
        endif()
    endforeach()

    list(SORT _native_copied_bas_sources)
    list(SORT _generated_backend_files)
    set(_fbc_flags -gen ${_native_backend} -r -m fbc -i "${CMAKE_SOURCE_DIR}/inc" -target ${FB_TARGET_ID})
    if(FB_COMPILER_DEBUG)
        list(APPEND _fbc_flags -g -exx)
    endif()
    if(FB_STANDALONE)
        list(APPEND _fbc_flags -d ENABLE_STANDALONE)
    endif()

    # One fbc invocation emits all known backend outputs from the copied BAS
    # files.
    add_custom_command(
        OUTPUT ${_generated_backend_files}
        COMMAND ${FBC_EXECUTABLE} ${_fbc_flags} ${_native_copied_bas_sources}
        WORKING_DIRECTORY "${_native_source_dir}"
        DEPENDS ${_native_copied_inputs}
        COMMENT "Generating native compiler ${_native_backend} sources"
        VERBATIM
    )

    # The HLC backend emits computed-goto expressions that clang requires us
    # to rewrite before compilation.  PRE_BUILD runs too late for object-file
    # compilation, so prepare a fixed generated source for every output.
    set(_native_compile_sources ${_generated_backend_files})
    if(FB_USING_CLANG AND _native_backend STREQUAL "gcc")
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        set(_native_fixed_sources "")
        foreach(_src ${_generated_backend_files})
            get_filename_component(_name "${_src}" NAME)
            set(_fixed "${CMAKE_CURRENT_BINARY_DIR}/native-fixed/${_name}")
            file(RELATIVE_PATH _fixed_relative "${CMAKE_CURRENT_BINARY_DIR}" "${_fixed}")
            add_custom_command(
                OUTPUT "${_fixed}"
                COMMAND ${CMAKE_COMMAND} -E make_directory
                        "${CMAKE_CURRENT_BINARY_DIR}/native-fixed"
                COMMAND ${CMAKE_COMMAND} -E copy "${_src}" "${_fixed}"
                COMMAND ${Python3_EXECUTABLE}
                        "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
                        "${_fixed_relative}"
                WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
                DEPENDS "${_src}" "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
                COMMENT "Preparing ${_name} for clang"
                VERBATIM
            )
            list(APPEND _native_fixed_sources "${_fixed}")
        endforeach()
        set(_native_compile_sources ${_native_fixed_sources})
    endif()

    if(_native_backend STREQUAL "gas64")
        set_source_files_properties(${_native_compile_sources} PROPERTIES LANGUAGE ASM)
    endif()

    add_custom_target(fbc_generate DEPENDS ${_native_compile_sources})

    add_executable(fbc ${_native_compile_sources})
    add_dependencies(fbc fbc_generate)

    if(_native_backend STREQUAL "gcc")
        target_compile_options(fbc PRIVATE
            -nostdinc
            ${FB_BOOTSTRAP_C_FLAGS}
            ${FB_BOOTSTRAP_C_WARNINGS}
            -O2
        )
    else()
        # fbc writes GNU assembler with a .asm extension.  GCC only infers an
        # assembler input language from .s/.S, so select it explicitly.
        target_compile_options(fbc PRIVATE
            "$<$<COMPILE_LANGUAGE:ASM>:-x>"
            "$<$<COMPILE_LANGUAGE:ASM>:assembler>"
        )
        # The historical gas64 path links with ld directly, producing a
        # non-PIE executable.  Its raw assembler is not compiled with GCC's
        # PIE defaults, so retain that ABI when CMake links through GCC.
        target_link_options(fbc PRIVATE -no-pie)
    endif()

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
