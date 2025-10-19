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
find_package(FLEX REQUIRED)

bison_target(sv2017_parser
    ./src/compiler/sv2017/parser.y
    ./src/compiler/sv2017/parser.cpp
    DEFINES_FILE ${CMAKE_SOURCE_DIR}/src/compiler/sv2017/parser.h)
flex_target(sv2017_scanner ./src/compiler/sv2017/scanner.l ./src/compiler/sv2017/scanner.cpp)
add_flex_bison_dependency(sv2017_scanner sv2017_parser)

message("${BISON_sv2017_parser_OUTPUT_HEADER}")

add_library(sv2017_front_end STATIC
    ${BISON_sv2017_parser_OUTPUTS}
    ${FLEX_sv2017_scanner_OUTPUTS})

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
            ./test/compiler/grammar/sv2017/identifier_tests.cpp
            ./test/compiler/grammar/sv2017/string_literal_tests.cpp
            ./test/compiler/grammar/sv2017/number_tests.cpp
            ./test/compiler/grammar/sv2017/operator_tests.cpp
    )
    target_link_libraries(cpp_test
        PRIVATE
            svsc
            foonathan::lexy
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(cpp_test)

endif()
