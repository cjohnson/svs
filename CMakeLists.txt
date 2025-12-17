cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(svs LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.12.0
)
FetchContent_MakeAvailable(json)

add_library(sv2017_json STATIC)
target_sources(sv2017_json
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/json/serializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/json/visitor.cpp)
target_link_libraries(sv2017_json PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(sv2017_json PRIVATE src)

add_library(sv2017_ast STATIC)
target_sources(sv2017_ast
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/ansi_port_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/data_type.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/description.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/integer_vector_data_type.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/integer_vector_type.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/lifetime.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/module_ansi_header.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/module_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/module_header.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/node.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/port_direction.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/source_text.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/time_literal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/time_unit.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/timeunits_declaration.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/variable_port_header.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/ast/visitor.cpp)
target_include_directories(sv2017_ast PRIVATE src)

find_package(BISON REQUIRED)
bison_target(sv2017_bison
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser.y
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser.generated.cpp
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser.generated.h)

find_package(FLEX REQUIRED)
flex_target(sv2017_flex
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner.l
    ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner.generated.cpp
    DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/scanner.generated.h)
add_flex_bison_dependency(sv2017_flex sv2017_bison)

add_library(svsc2017 STATIC)
target_sources(svsc2017
    PRIVATE
        ${BISON_sv2017_bison_OUTPUTS}
        ${FLEX_sv2017_flex_OUTPUTS}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compiler/sv2017/parser.cpp)
target_link_libraries(svsc2017 PRIVATE sv2017_ast)
target_include_directories(svsc2017 PRIVATE src)

add_executable(svs ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(svs PRIVATE svsc2017 sv2017_json)
target_include_directories(svs PRIVATE src)

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

    #add_executable(cpp_test)
    #target_sources(cpp_test
    #    PRIVATE
    #)
    #target_include_directories(cpp_test PRIVATE src/compiler)
    #target_link_libraries(cpp_test
    #    PRIVATE
    #        svsc2017
    #        GTest::gtest_main
    #)

    include(GoogleTest)
    #gtest_discover_tests(cpp_test)
endif()
