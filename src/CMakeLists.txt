project(datastructures-cpp-example)
cmake_minimum_required(VERSION 3.5)

set(DATASTRUCTURES_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
set(DATASTRUCTURES_CPP_SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${DATASTRUCTURES_CPP_SOURCES})