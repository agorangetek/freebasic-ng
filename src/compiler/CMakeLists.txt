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

    # Work from a build-tree copy of the compiler sources.  The generated-C
    # mode writes -r output next to its inputs; the object mode keeps the
    # seed compiler's intermediate files out of the source tree too.
    set(_native_backend "${FB_NATIVE_COMPILER_BACKEND}")
    set(_native_output_extension "c")
    if(_native_backend STREQUAL "gas64")
        enable_language(ASM)
        set(_native_output_extension "asm")
    endif()
    set(_native_source_dir "${CMAKE_CURRENT_BINARY_DIR}/native-source")
    set(_native_copied_inputs "")
    set(_native_copied_bas_sources "")
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
        endif()
    endforeach()

    list(SORT _native_copied_bas_sources)
    set(_fbc_flags -gen ${_native_backend} -m fbc -i "${CMAKE_SOURCE_DIR}/inc" -target ${FB_TARGET_ID})
    if(FB_COMPILER_DEBUG)
        list(APPEND _fbc_flags -g -exx)
    endif()
    if(FB_STANDALONE)
        list(APPEND _fbc_flags -d ENABLE_STANDALONE)
    endif()

    if(FB_NATIVE_COMPILER_OBJECTS)
        # GNU make builds the compiler as separate FreeBASIC modules.  Keep
        # this option for historical ABI verification: it lets the seed fbc
        # invoke its configured C toolchain (or the x86 GAS backend) for every
        # module, then lets CMake perform the final link against the
        # CMake-built runtime.
        set(_native_object_dir "${CMAKE_CURRENT_BINARY_DIR}/native-objects")
        set(_native_compile_sources "")
        foreach(_source IN LISTS _native_copied_bas_sources)
            get_filename_component(_base "${_source}" NAME_WE)
            set(_object "${_native_object_dir}/${_base}.o")
            add_custom_command(
                OUTPUT "${_object}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${_native_object_dir}"
                COMMAND ${FBC_EXECUTABLE} ${_fbc_flags} -e -w pedantic -c
                        "${_source}" -o "${_object}"
                WORKING_DIRECTORY "${_native_source_dir}"
                DEPENDS ${_native_copied_inputs}
                COMMENT "Compiling native compiler module ${_base}"
                VERBATIM
            )
            list(APPEND _native_compile_sources "${_object}")
        endforeach()
        set_source_files_properties(${_native_compile_sources} PROPERTIES
            EXTERNAL_OBJECT TRUE)
    else()
        set(_generated_backend_files "")
        foreach(_source IN LISTS _native_copied_bas_sources)
            get_filename_component(_base "${_source}" NAME_WE)
            list(APPEND _generated_backend_files
                "${_native_source_dir}/${_base}.${_native_output_extension}")
        endforeach()
        list(SORT _generated_backend_files)

        # One fbc invocation emits all known backend outputs from the copied
        # BAS files.
        add_custom_command(
            OUTPUT ${_generated_backend_files}
            COMMAND ${FBC_EXECUTABLE} ${_fbc_flags} -r ${_native_copied_bas_sources}
            WORKING_DIRECTORY "${_native_source_dir}"
            DEPENDS ${_native_copied_inputs}
            COMMENT "Generating native compiler ${_native_backend} sources"
            VERBATIM
        )

        # The HLC backend emits computed-goto expressions that clang requires
        # us to rewrite before compilation.  PRE_BUILD runs too late for
        # object-file compilation, so prepare a fixed generated source for
        # every output.
        set(_native_compile_sources ${_generated_backend_files})
        if(FB_USING_CLANG AND _native_backend STREQUAL "gcc")
            find_package(Python3 COMPONENTS Interpreter REQUIRED)
            # CMake passes native C:/ paths to custom commands, while the
            # CLANGARM64 Python executable is an MSYS program. Give it a
            # script path relative to the compiler build directory, as in the
            # bootstrap-mode computed-goto preparation above.
            file(REAL_PATH "${CMAKE_CURRENT_BINARY_DIR}"
                _native_fix_working_directory)
            file(REAL_PATH "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
                _native_fix_script_absolute)
            file(RELATIVE_PATH _native_fix_script
                "${_native_fix_working_directory}"
                "${_native_fix_script_absolute}")
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
                            "${_native_fix_script}"
                            "${_fixed_relative}"
                    WORKING_DIRECTORY "${_native_fix_working_directory}"
                    DEPENDS "${_src}" "${CMAKE_SOURCE_DIR}/cmake/fix_computed_goto.py"
                    COMMENT "Preparing ${_name} for clang"
                    VERBATIM
                )
                list(APPEND _native_fixed_sources "${_fixed}")
            endforeach()
            set(_native_compile_sources ${_native_fixed_sources})
        endif()
    endif()

    if(_native_backend STREQUAL "gas64")
        set_source_files_properties(${_native_compile_sources} PROPERTIES LANGUAGE ASM)
    endif()

    add_custom_target(fbc_generate DEPENDS ${_native_compile_sources})

    set(FBRT0_OBJ "${CMAKE_BINARY_DIR}/src/rtlib/fbrt0.o")
    set(_native_gas_object_link FALSE)
    if(_native_backend STREQUAL "gas" AND FB_NATIVE_COMPILER_OBJECTS)
        set(_native_gas_object_link TRUE)
    endif()

    if(_native_gas_object_link)
        # The historical x86 build asked fbc to link the compiler objects.
        # Its direct GNU ld invocation is materially different from CMake's
        # compiler-driver link.  The first bootstrap generation must retain
        # the seed runtime, exactly as Travis did.  The second generation gets
        # a private prefix containing CMake's freshly built runtime, so the
        # final compiler remains a CMake build rather than falling back to the
        # root makefile.
        set(_native_link_prefix "${CMAKE_CURRENT_BINARY_DIR}/native-link-runtime")
        set(_native_link_libdir "${_native_link_prefix}/lib/freebasic/${FB_TARGET_ID}")
        set(_native_fbc "${CMAKE_CURRENT_BINARY_DIR}/fbc")
        if(FB_NATIVE_COMPILER_LINK_WITH_SEED_RUNTIME)
            add_custom_command(
                OUTPUT "${_native_fbc}"
                COMMAND ${FBC_EXECUTABLE} -target ${FB_TARGET_ID}
                        -e -m fbc -w pedantic -x "${_native_fbc}"
                        ${_native_compile_sources}
                DEPENDS fbc_generate
                COMMENT "Linking native x86 GAS bootstrap compiler through fbc"
                COMMAND_EXPAND_LISTS
                VERBATIM
            )
        else()
            add_custom_command(
                OUTPUT "${_native_fbc}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${_native_link_libdir}"
                COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:fb>"
                        "${_native_link_libdir}/libfb.a"
                COMMAND ${CMAKE_COMMAND} -E copy_if_different "${FBRT0_OBJ}"
                        "${_native_link_libdir}/fbrt0.o"
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                        "${CMAKE_SOURCE_DIR}/lib/fbextra.x"
                        "${_native_link_libdir}/fbextra.x"
                COMMAND ${FBC_EXECUTABLE} -prefix "${_native_link_prefix}"
                        -target ${FB_TARGET_ID} -e -m fbc -w pedantic
                        -x "${_native_fbc}" ${_native_compile_sources}
                DEPENDS fbc_generate fb fbrt0
                        "${CMAKE_SOURCE_DIR}/lib/fbextra.x"
                COMMENT "Linking native x86 GAS compiler through fbc"
                COMMAND_EXPAND_LISTS
                VERBATIM
            )
        endif()
        # A custom target named fbc would collide with the generated fbc
        # executable path in Ninja.  The narrow native-GAS path has no CMake
        # executable target because fbc itself performs the final link.
        add_custom_target(fbc_native ALL DEPENDS "${_native_fbc}")
    else()
        add_executable(fbc ${_native_compile_sources})
        add_dependencies(fbc fbc_generate)
        if(FB_NATIVE_COMPILER_OBJECTS)
            # External object files do not let CMake infer a link language.
            set_target_properties(fbc PROPERTIES LINKER_LANGUAGE C)
        endif()

        if(_native_backend STREQUAL "gcc" AND NOT FB_NATIVE_COMPILER_OBJECTS)
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

        target_link_options(fbc PRIVATE "${FBRT0_OBJ}")
        add_dependencies(fbc fbrt0)
    endif()

endif()

# --- Installation ---
if(DEFINED _native_gas_object_link AND _native_gas_object_link)
    install(PROGRAMS "${_native_fbc}" DESTINATION "${FB_INSTALL_BINDIR}")
else()
    install(TARGETS fbc RUNTIME DESTINATION "${FB_INSTALL_BINDIR}")
endif()
