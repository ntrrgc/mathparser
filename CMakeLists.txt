project(mathbuilder)
cmake_minimum_required(VERSION 2.8)

find_package(BISON)
find_package(FLEX)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated/bison)

flex_target(MathScanner MathScanner.l 
    ${CMAKE_CURRENT_BINARY_DIR}/generated/bison/MathScanner.yy.cpp)
bison_target(MathParser MathParser.ypp 
    ${CMAKE_CURRENT_BINARY_DIR}/generated/bison/MathParser.tab.cpp)
add_flex_bison_dependency(MathScanner MathParser)
    
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
include_directories(
    .
    ${CMAKE_CURRENT_BINARY_DIR}/generated)
file(GLOB SRC_LIST "*.hpp" "*.cpp" "*.h" "ast/*.hpp" "ast/*.cpp" "MathParser.ypp" "MathScanner.l")

add_library(MathParser SHARED 
    ${SRC_LIST} ${BISON_MathParser_OUTPUTS} ${FLEX_MathScanner_OUTPUTS})

add_executable(MathParserExampleCpp
    MathParser
    "examples/calculator.cpp")
target_link_libraries(MathParserExampleCpp MathParser)

add_executable(MathParserExampleC
    MathParser
    "examples/calculator_c.c")
target_link_libraries(MathParserExampleC MathParser)

add_executable(MathParserValuesExample
    MathParser
    "examples/values.cpp")
target_link_libraries(MathParserValuesExample MathParser)
