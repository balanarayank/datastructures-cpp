project(simple-cpp-datastructures)
cmake_minimum_required(VERSION 3.14)

set(LINKEDLIST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${LINKEDLIST_INC_DIR})

set(EXAMPLES_CPP_SOURCES examples/SinglyLinkedList.cpp)
add_executable(${PROJECT_NAME} ${EXAMPLES_CPP_SOURCES})

add_subdirectory(tests)