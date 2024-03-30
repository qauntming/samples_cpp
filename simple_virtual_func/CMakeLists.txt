cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(testprj)


set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE TEST_CXX_SRC *.cc)


add_executable( ${PROJECT_NAME}  ${TEST_CXX_SRC} )

