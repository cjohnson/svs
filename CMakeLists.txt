cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(svs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_library(svs
    STATIC
        ./src/parser/parser.cpp

        # SystemVerilog 2017
        ./src/parser/sv2017/comment_parser.cpp
        ./src/parser/sv2017/identifier_parser.cpp
        ./src/parser/sv2017/white_space_parser.cpp
)

add_executable(svsc ./src/main.cpp)
target_link_libraries(svsc svs)

option(ENABLE_UNIT_TESTS "Enable Unit Tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if (ENABLE_UNIT_TESTS)
    include(FetchContent)

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

    add_executable(cpp_test
        ./test/parser/parser_tests.cpp

        # SystemVerilog 2017
        ./test/parser/sv2017/comment_parser_tests.cpp
        ./test/parser/sv2017/identifier_parser_tests.cpp
        ./test/parser/sv2017/white_space_parser_tests.cpp
    )
    target_link_libraries(cpp_test svs GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(cpp_test)

endif()
