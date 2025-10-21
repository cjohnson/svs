cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(svs LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include(FetchContent)

FetchContent_Declare(
    lexy
    URL https://github.com/foonathan/lexy/releases/download/v2025.05.0/lexy-src.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(lexy)

add_library(svsc STATIC)
target_sources(svsc
    PRIVATE
        ./src/compiler/sv2017/ast_number.cpp
        ./src/compiler/sv2017/ast_visitor.cpp
        ./src/compiler/sv2017/grammar_identifier.hpp
)
target_link_libraries(svsc PRIVATE foonathan::lexy)

find_package(BISON REQUIRED)
bison_target(sv2017_parser_impl
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser.y
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser_impl.cpp
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser_impl.h)

find_package(FLEX REQUIRED)
flex_target(sv2017_scanner_impl
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner.l
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner_impl.cpp
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner_impl.h)
add_flex_bison_dependency(sv2017_scanner_impl sv2017_parser_impl)

add_library(sv2017_scanner STATIC)
target_sources(sv2017_scanner
    PRIVATE
        ${BISON_sv2017_parser_impl_OUTPUTS}
        ${FLEX_sv2017_scanner_impl_OUTPUTS}
        ./src/compiler/sv2017/scanner.cpp)
target_include_directories(sv2017_scanner
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017)

add_library(sv2017_parser STATIC)
target_sources(sv2017_parser
    PRIVATE
        ${BISON_sv2017_parser_impl_OUTPUTS}
        ${FLEX_sv2017_scanner_impl_OUTPUTS})
target_include_directories(sv2017_parser PRIVATE src/compiler/sv2017)

add_library(svsc2017 STATIC)
target_sources(svsc2017
    PRIVATE
        ${BISON_sv2017_parser_impl_OUTPUTS}
        ${FLEX_sv2017_scanner_impl_OUTPUTS})
target_link_libraries(svsc2017
    PRIVATE
        sv2017_scanner
        sv2017_parser)

option(ENABLE_UNIT_TESTS "Enable Unit Tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if (ENABLE_UNIT_TESTS)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.17.0
    )

    FetchContent_GetProperties(googletest)

    if (NOT googletest_POPULATED)
        # Prevent GoogleTest from overriding our compiler/linker options
        # when building with Visual Studio
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        FetchContent_MakeAvailable(googletest)
    endif()

    enable_testing()

    add_executable(cpp_test)
    target_sources(cpp_test
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/test/compiler/sv2017/identifier_tests.cpp
            ./test/compiler/grammar/sv2017/string_literal_tests.cpp
            ./test/compiler/grammar/sv2017/number_tests.cpp
            ./test/compiler/grammar/sv2017/operator_tests.cpp
    )
    target_include_directories(cpp_test PRIVATE src/compiler)
    target_link_libraries(cpp_test
        PRIVATE
            svsc2017
            svsc
            foonathan::lexy
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(cpp_test)
endif()
