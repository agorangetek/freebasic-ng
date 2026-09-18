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

project(FreeBASICNG VERSION ${FREEBASIC_NG_VERSION} LANGUAGES C ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# FreeBASIC-NG requires GCC or Clang (MinGW on Windows)
if(MSVC)
    message(FATAL_ERROR
        "MSVC is not supported. Use MinGW-w64 on Windows.\n"
        "Configure with: cmake -G \"MinGW Makefiles\" or use MSYS2.")
endif()

# Options
option(FB_STANDALONE "Build as self-contained installation" OFF)
option(FB_BUILD_GFXLIB "Build the graphics library" ON)
option(FB_BUILD_COMPILER "Build the fbc compiler" ON)
option(FB_BUILD_TESTS "Build tests" OFF)
option(FB_BUILD_LEGACY_UNIT_TESTS
    "Run the historical fbcunit suite through CTest" OFF)
option(FB_VERIFY_LEGACY_UNIT_FAILURE_DETECTION
    "Verify that the historical fbcunit adapter rejects an injected failing fixture" OFF)
option(FB_BUILD_LEGACY_LOG_TESTS
    "Run the historical log-test suite through CTest" OFF)
option(FB_BUILD_LEGACY_WARNING_TESTS
    "Run the historical warning fixtures through CTest" OFF)
option(FB_BUILD_LEGACY_SYNTAX_TESTS
    "Run the historical syntax fixtures through CTest" OFF)
option(FB_BUILD_LEGACY_DOC_TOOLS
    "Build the historical documentation tools through CTest" OFF)
option(FB_COMPILER_DEBUG
    "Enable the historical compiler debug configuration" OFF)
option(FB_LEGACY_TEST_DEBUG
    "Pass the historical -g -exx flags to legacy runtime test suites" OFF)
option(FB_USE_SYSTEM_FBC "Use an existing fbc instead of the verified bootstrap seed" OFF)
option(FB_DOWNLOAD_BOOTSTRAP_SEED
    "Download the provenance-verified minimal compiler seed when no fbc is available" ON)
set(FB_BOOTSTRAP_SEED_CACHE "${CMAKE_BINARY_DIR}/bootstrap-seeds" CACHE PATH
    "Directory used to cache verified minimal compiler seeds")
set(FB_NATIVE_COMPILER_BACKEND "gcc" CACHE STRING
    "Backend used when a system fbc builds the native compiler (gcc, gas, or gas64)")
set_property(CACHE FB_NATIVE_COMPILER_BACKEND PROPERTY STRINGS gcc gas gas64)
if(NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gcc" AND
   NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gas" AND
   NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gas64")
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_BACKEND must be one of: gcc, gas, gas64")
endif()
option(FB_NATIVE_COMPILER_OBJECTS
    "Compile native compiler modules individually through fbc before CMake links them" OFF)
option(FB_NATIVE_COMPILER_LINK_WITH_SEED_RUNTIME
    "Link the native x86 GAS bootstrap compiler through the seed runtime" OFF)
if(FB_NATIVE_COMPILER_OBJECTS AND
   NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gcc" AND
   NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gas")
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_OBJECTS currently requires FB_NATIVE_COMPILER_BACKEND=gcc or gas")
endif()
if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas" AND
   NOT FB_NATIVE_COMPILER_OBJECTS)
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_BACKEND=gas requires FB_NATIVE_COMPILER_OBJECTS=ON")
endif()
if(FB_NATIVE_COMPILER_LINK_WITH_SEED_RUNTIME AND
   (NOT FB_NATIVE_COMPILER_BACKEND STREQUAL "gas" OR
    NOT FB_NATIVE_COMPILER_OBJECTS))
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_LINK_WITH_SEED_RUNTIME requires native x86 GAS objects")
endif()

# The Developer Preview archives use the ordinary Unix-style layout.  A
# standalone compiler additionally needs its C toolchain below the prefix, but
# that toolchain is intentionally not shipped in M1.  Refuse the combination
# explicitly instead of producing an installation which cannot compile.
if(FB_STANDALONE)
    message(FATAL_ERROR
        "FB_STANDALONE is not available in the Developer Preview. "
        "Build with -DFB_STANDALONE=OFF; the installed compiler uses the platform C toolchain.")
endif()

# Platform detection (sets FB_TARGET_OS, FB_TARGET_ARCH, FB_TARGET_ID)
include(cmake/DetectPlatform.cmake)

# The historical gas64 backend emits GNU assembler for the Linux x86_64 ABI.
# Keep the CMake option equally narrow until another qualified host exists.
if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas64" AND
   (NOT FB_TARGET_OS STREQUAL "linux" OR
    NOT FB_TARGET_ARCH STREQUAL "x86_64" OR
    NOT CMAKE_C_COMPILER_ID STREQUAL "GNU"))
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_BACKEND=gas64 currently requires Linux x86_64 with GCC")
endif()

# The historical 32-bit Travis matrix built compiler modules through the
# original GAS backend.  CMake supports it only in the matching object mode;
# generated assembly is not a general native-build path yet.
if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas" AND
   (NOT FB_TARGET_OS STREQUAL "linux" OR
    NOT FB_TARGET_ARCH STREQUAL "x86" OR
    NOT CMAKE_C_COMPILER_ID STREQUAL "GNU"))
    message(FATAL_ERROR
        "FB_NATIVE_COMPILER_BACKEND=gas currently requires Linux x86 with GCC")
endif()

# Bootstrap logic (determines how to build fbc)
if(FB_BUILD_COMPILER)
    include(cmake/Bootstrap.cmake)
    if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas64" AND
       NOT FB_BOOTSTRAP_MODE STREQUAL "native")
        message(FATAL_ERROR
            "FB_NATIVE_COMPILER_BACKEND=gas64 requires a working system fbc; "
            "configure with -DFB_USE_SYSTEM_FBC=ON")
    endif()
    if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas" AND
       NOT FB_BOOTSTRAP_MODE STREQUAL "native")
        message(FATAL_ERROR
            "FB_NATIVE_COMPILER_BACKEND=gas requires a working system fbc; "
            "configure with -DFB_USE_SYSTEM_FBC=ON")
    endif()
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

if(FB_BUILD_TESTS OR FB_BUILD_LEGACY_UNIT_TESTS OR
   FB_VERIFY_LEGACY_UNIT_FAILURE_DETECTION OR FB_BUILD_LEGACY_LOG_TESTS OR
   FB_BUILD_LEGACY_WARNING_TESTS OR FB_BUILD_LEGACY_SYNTAX_TESTS OR
   FB_BUILD_LEGACY_DOC_TOOLS)
    enable_testing()

    # Portable compiler regressions.  They are built and run by the compiler
    # from this build, so they cover the generated code, not only the parser.
    if(FB_BUILD_COMPILER)
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        add_test(
            NAME compiler.data-statement
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-compiler-regression.py"
                --cmake "${CMAKE_COMMAND}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${CMAKE_BINARY_DIR}/tests/data-statement/stage"
                --source "${CMAKE_SOURCE_DIR}/test/cmake/data-statement.bas"
                --work-dir "${CMAKE_BINARY_DIR}/tests/data-statement/work"
        )
        add_test(
            NAME compiler.error-check-handler
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-compiler-regression.py"
                --cmake "${CMAKE_COMMAND}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${CMAKE_BINARY_DIR}/tests/error-check-handler/stage"
                --source "${CMAKE_SOURCE_DIR}/test/cmake/error-check-handler.bas"
                --work-dir "${CMAKE_BINARY_DIR}/tests/error-check-handler/work"
                --fbc-flag=-e
        )
    endif()

    # Darwin arm64 uses a pointer __builtin_va_list.  This regression must be
    # built by the native/self-hosted compiler so it validates the generated
    # C path as well as the target ABI model.
    if(FB_BUILD_COMPILER AND FB_TARGET_OS STREQUAL "darwin" AND
       FB_TARGET_ARCH STREQUAL "aarch64")
        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        add_test(
            NAME compiler.darwin-aarch64-cva-list
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-compiler-regression.py"
                --cmake "${CMAKE_COMMAND}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${CMAKE_BINARY_DIR}/tests/darwin-aarch64-cva-list/stage"
                --source "${CMAKE_SOURCE_DIR}/test/cmake/darwin-aarch64-cva-list.bas"
                --work-dir "${CMAKE_BINARY_DIR}/tests/darwin-aarch64-cva-list/work"
        )
        add_test(
            NAME compiler.darwin-aarch64-consteval-acos
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-compiler-regression.py"
                --cmake "${CMAKE_COMMAND}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${CMAKE_BINARY_DIR}/tests/darwin-aarch64-consteval-acos/stage"
                --source "${CMAKE_SOURCE_DIR}/test/cmake/darwin-aarch64-consteval-acos.bas"
                --work-dir "${CMAKE_BINARY_DIR}/tests/darwin-aarch64-consteval-acos/work"
        )
    endif()

    # Travis varied compiler debug and the runtime test flags independently.
    # Warning and syntax fixtures intentionally stay outside this list: their
    # expected diagnostic output depends on unstable debug temporary names.
    set(_fb_legacy_runtime_test_fbc_args)
    if(FB_LEGACY_TEST_DEBUG)
        list(APPEND _fb_legacy_runtime_test_fbc_args
            --fbc-flag=-g
            --fbc-flag=-exx
        )
    endif()
    if(FB_NATIVE_COMPILER_BACKEND STREQUAL "gas64")
        list(APPEND _fb_legacy_runtime_test_fbc_args
            --fbc-flag=-gen
            --fbc-flag=gas64
        )
    endif()

    if(FB_BUILD_LEGACY_UNIT_TESTS)
        if(NOT FB_BUILD_COMPILER)
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_UNIT_TESTS requires FB_BUILD_COMPILER=ON")
        endif()
        if(NOT FB_BUILD_GFXLIB)
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_UNIT_TESTS requires FB_BUILD_GFXLIB=ON because the unit suite links -fbgfx")
        endif()

        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        find_program(FB_LEGACY_TEST_MAKE NAMES gmake make REQUIRED)
        set(_fb_legacy_unit_dir "${CMAKE_BINARY_DIR}/tests/legacy-unit")
        set(_fb_legacy_unit_runner "${CMAKE_SOURCE_DIR}/scripts/run-legacy-unit-tests.py")
        set(_fb_legacy_unit_cmake "${CMAKE_COMMAND}")
        set(_fb_legacy_unit_make "${FB_LEGACY_TEST_MAKE}")
        set(_fb_legacy_unit_build_dir "${CMAKE_BINARY_DIR}")
        set(_fb_legacy_unit_install_prefix "${_fb_legacy_unit_dir}/stage")
        set(_fb_legacy_unit_source_tests_dir "${CMAKE_SOURCE_DIR}/tests")
        set(_fb_legacy_unit_source_include_dir "${CMAKE_SOURCE_DIR}/inc")
        set(_fb_legacy_unit_work_dir "${_fb_legacy_unit_dir}/work")
        set(_fb_legacy_unit_log "${_fb_legacy_unit_dir}/unit-tests.log")

        # MSYS Python treats C:/... arguments as POSIX-relative paths. Run
        # the adapter from the build tree and pass only portable relative
        # paths to its subprocess calls on Windows.
        if(WIN32)
            file(RELATIVE_PATH _fb_legacy_unit_runner "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_runner}")
            file(RELATIVE_PATH _fb_legacy_unit_source_tests_dir "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_source_tests_dir}")
            file(RELATIVE_PATH _fb_legacy_unit_source_include_dir "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_source_include_dir}")
            set(_fb_legacy_unit_cmake cmake)
            set(_fb_legacy_unit_make make)
            set(_fb_legacy_unit_build_dir .)
            set(_fb_legacy_unit_install_prefix tests/legacy-unit/stage)
            set(_fb_legacy_unit_work_dir tests/legacy-unit/work)
            set(_fb_legacy_unit_log tests/legacy-unit/unit-tests.log)
        endif()
        add_test(
            NAME legacy.unit
            COMMAND "${Python3_EXECUTABLE}"
                "${_fb_legacy_unit_runner}"
                --cmake "${_fb_legacy_unit_cmake}"
                --make "${_fb_legacy_unit_make}"
                --build-dir "${_fb_legacy_unit_build_dir}"
                --install-prefix "${_fb_legacy_unit_install_prefix}"
                --source-tests-dir "${_fb_legacy_unit_source_tests_dir}"
                --source-include-dir "${_fb_legacy_unit_source_include_dir}"
                --work-dir "${_fb_legacy_unit_work_dir}"
                --log "${_fb_legacy_unit_log}"
                ${_fb_legacy_runtime_test_fbc_args}
        )
        set_tests_properties(legacy.unit PROPERTIES
            LABELS "legacy;unit"
            TIMEOUT 1800
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        )
    endif()

    if(FB_VERIFY_LEGACY_UNIT_FAILURE_DETECTION)
        if(NOT FB_BUILD_COMPILER)
            message(FATAL_ERROR
                "FB_VERIFY_LEGACY_UNIT_FAILURE_DETECTION requires FB_BUILD_COMPILER=ON")
        endif()
        if(NOT FB_BUILD_GFXLIB)
            message(FATAL_ERROR
                "FB_VERIFY_LEGACY_UNIT_FAILURE_DETECTION requires FB_BUILD_GFXLIB=ON")
        endif()

        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        find_program(FB_LEGACY_TEST_MAKE NAMES gmake make REQUIRED)
        set(_fb_legacy_unit_negative_dir "${CMAKE_BINARY_DIR}/tests/legacy-unit-negative")
        set(_fb_legacy_unit_negative_runner "${CMAKE_SOURCE_DIR}/scripts/run-legacy-unit-tests.py")
        set(_fb_legacy_unit_negative_cmake "${CMAKE_COMMAND}")
        set(_fb_legacy_unit_negative_make "${FB_LEGACY_TEST_MAKE}")
        set(_fb_legacy_unit_negative_build_dir "${CMAKE_BINARY_DIR}")
        set(_fb_legacy_unit_negative_install_prefix "${_fb_legacy_unit_negative_dir}/stage")
        set(_fb_legacy_unit_negative_source_tests_dir "${CMAKE_SOURCE_DIR}/tests")
        set(_fb_legacy_unit_negative_source_include_dir "${CMAKE_SOURCE_DIR}/inc")
        set(_fb_legacy_unit_negative_work_dir "${_fb_legacy_unit_negative_dir}/work")
        set(_fb_legacy_unit_negative_log "${_fb_legacy_unit_negative_dir}/unit-tests.log")

        if(WIN32)
            file(RELATIVE_PATH _fb_legacy_unit_negative_runner "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_negative_runner}")
            file(RELATIVE_PATH _fb_legacy_unit_negative_source_tests_dir "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_negative_source_tests_dir}")
            file(RELATIVE_PATH _fb_legacy_unit_negative_source_include_dir "${CMAKE_BINARY_DIR}"
                "${_fb_legacy_unit_negative_source_include_dir}")
            set(_fb_legacy_unit_negative_cmake cmake)
            set(_fb_legacy_unit_negative_make make)
            set(_fb_legacy_unit_negative_build_dir .)
            set(_fb_legacy_unit_negative_install_prefix tests/legacy-unit-negative/stage)
            set(_fb_legacy_unit_negative_work_dir tests/legacy-unit-negative/work)
            set(_fb_legacy_unit_negative_log tests/legacy-unit-negative/unit-tests.log)
        endif()
        add_test(
            NAME legacy.unit-negative
            COMMAND "${Python3_EXECUTABLE}"
                "${_fb_legacy_unit_negative_runner}"
                --cmake "${_fb_legacy_unit_negative_cmake}"
                --make "${_fb_legacy_unit_negative_make}"
                --build-dir "${_fb_legacy_unit_negative_build_dir}"
                --install-prefix "${_fb_legacy_unit_negative_install_prefix}"
                --source-tests-dir "${_fb_legacy_unit_negative_source_tests_dir}"
                --source-include-dir "${_fb_legacy_unit_negative_source_include_dir}"
                --work-dir "${_fb_legacy_unit_negative_work_dir}"
                --log "${_fb_legacy_unit_negative_log}"
                --inject-failing-fixture
                --expect-failure
                ${_fb_legacy_runtime_test_fbc_args}
        )
        set_tests_properties(legacy.unit-negative PROPERTIES
            LABELS "legacy;unit;negative"
            TIMEOUT 1800
            WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        )
    endif()

    if(FB_BUILD_LEGACY_LOG_TESTS)
        if(NOT FB_BUILD_COMPILER)
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_LOG_TESTS requires FB_BUILD_COMPILER=ON")
        endif()
        if(NOT FB_BUILD_GFXLIB)
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_LOG_TESTS requires FB_BUILD_GFXLIB=ON because log tests link -fbgfx")
        endif()

        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        find_program(FB_LEGACY_TEST_MAKE NAMES gmake make REQUIRED)
        set(_fb_legacy_log_dir "${CMAKE_BINARY_DIR}/tests/legacy-log")
        add_test(
            NAME legacy.log
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-legacy-log-tests.py"
                --cmake "${CMAKE_COMMAND}"
                --make "${FB_LEGACY_TEST_MAKE}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${_fb_legacy_log_dir}/stage"
                --source-tests-dir "${CMAKE_SOURCE_DIR}/tests"
                --source-include-dir "${CMAKE_SOURCE_DIR}/inc"
                --work-dir "${_fb_legacy_log_dir}/work"
                --log "${_fb_legacy_log_dir}/log-tests.log"
                ${_fb_legacy_runtime_test_fbc_args}
        )
        set_tests_properties(legacy.log PROPERTIES
            LABELS "legacy;log"
            TIMEOUT 1800
        )
    endif()

    function(fb_add_legacy_compiler_output_test suite option_name)
        if(NOT ${option_name})
            return()
        endif()
        if(NOT FB_BUILD_COMPILER)
            message(FATAL_ERROR "${option_name} requires FB_BUILD_COMPILER=ON")
        endif()

        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        set(_fb_legacy_output_dir "${CMAKE_BINARY_DIR}/tests/legacy-${suite}")
        add_test(
            NAME "legacy.${suite}"
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-legacy-compiler-output-tests.py"
                --cmake "${CMAKE_COMMAND}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${_fb_legacy_output_dir}/stage"
                --source-tests-dir "${CMAKE_SOURCE_DIR}/tests"
                --source-include-dir "${CMAKE_SOURCE_DIR}/inc"
                --suite "${suite}"
                --work-dir "${_fb_legacy_output_dir}/work"
                --log "${_fb_legacy_output_dir}/${suite}.log"
        )
        set_tests_properties("legacy.${suite}" PROPERTIES
            LABELS "legacy;${suite}"
            TIMEOUT 1800
        )
    endfunction()

    fb_add_legacy_compiler_output_test(warnings FB_BUILD_LEGACY_WARNING_TESTS)
    fb_add_legacy_compiler_output_test(syntax FB_BUILD_LEGACY_SYNTAX_TESTS)

    if(FB_BUILD_LEGACY_DOC_TOOLS)
        if(NOT FB_BUILD_COMPILER)
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_DOC_TOOLS requires FB_BUILD_COMPILER=ON")
        endif()
        if(NOT CMAKE_SYSTEM_NAME STREQUAL "Linux" OR
           NOT CMAKE_C_COMPILER_ID STREQUAL "GNU")
            message(FATAL_ERROR
                "FB_BUILD_LEGACY_DOC_TOOLS requires Linux/GCC: the historical documentation sources emit computed gotos which Clang rejects")
        endif()

        find_package(Python3 COMPONENTS Interpreter REQUIRED)
        find_program(FB_LEGACY_TEST_MAKE NAMES gmake make REQUIRED)
        set(_fb_legacy_doc_dir "${CMAKE_BINARY_DIR}/tests/legacy-doc-tools")
        add_test(
            NAME legacy.doc-tools
            COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_SOURCE_DIR}/scripts/run-legacy-doc-tools.py"
                --cmake "${CMAKE_COMMAND}"
                --make "${FB_LEGACY_TEST_MAKE}"
                --build-dir "${CMAKE_BINARY_DIR}"
                --install-prefix "${_fb_legacy_doc_dir}/stage"
                --source-doc-dir "${CMAKE_SOURCE_DIR}/doc"
                --work-dir "${_fb_legacy_doc_dir}/work"
                --log "${_fb_legacy_doc_dir}/doc-tools.log"
                ${_fb_legacy_runtime_test_fbc_args}
        )
        set_tests_properties(legacy.doc-tools PROPERTIES
            LABELS "legacy;documentation"
            TIMEOUT 1800
        )
    endif()
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
