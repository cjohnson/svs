cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(svs LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3")

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

#add_executable(svsc ./src/main.cpp)
#target_link_libraries(svsc svs)

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
