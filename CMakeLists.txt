project(simple-cpp-datastructures)
cmake_minimum_required(VERSION 3.14)

set(LINKEDLIST_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc CACHE INTERNAL "")

set(EXAMPLES_CPP_SOURCES examples/SinglyLinkedList.cpp)
add_executable(${PROJECT_NAME} ${EXAMPLES_CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${LINKEDLIST_INC_DIR})

add_subdirectory(tests)