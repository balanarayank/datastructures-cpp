project(datastructures-cpp-ut)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

#googletest
include(FetchContent)
FetchContent_Declare(googletest
GIT_REPOSITORY "https://github.com/google/googletest.git"
GIT_TAG "release-1.11.0"
)
FetchContent_MakeAvailable(googletest)

set(UT_CPP_SOURCES main_ut.cc)

add_executable(${PROJECT_NAME} ${UT_CPP_SOURCES})	
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(${PROJECT_NAME} gtest gtest_main gmock gmock_main Threads::Threads)
