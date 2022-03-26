project(datastructures-cpp-ut)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)
include(ExternalProject)
set(GTESTINSTALLPATH ${CMAKE_BINARY_DIR}/gtestinstallpath)
ExternalProject_Add(googletest
	GIT_REPOSITORY "https://github.com/google/googletest.git"
	GIT_TAG "release-1.11.0"
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTESTINSTALLPATH}
)
include_directories(${GTESTINSTALLPATH}/include ${CMAKE_CURRENT_SOURCE_DIR}/../src)
link_directories(${GTESTINSTALLPATH}/lib)
set(UT_CPP_SOURCES main_ut.cc SinglyLinkedList/SinglyLinkedList_ut.h)
add_executable(${PROJECT_NAME} ${UT_CPP_SOURCES})
add_dependencies(${PROJECT_NAME} googletest)
target_link_libraries(${PROJECT_NAME} gtest gtest_main gmock gmock_main Threads::Threads)

