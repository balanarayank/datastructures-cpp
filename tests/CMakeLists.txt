project(simple-cpp-datastructures-ut)
cmake_minimum_required(VERSION 3.14)

#GoogleTest version 1.11.0
include(FetchContent)
FetchContent_Declare( googletest
    GIT_REPOSITORY "https://github.com/google/googletest"
    GIT_TAG "release-1.11.0"
)
FetchContent_MakeAvailable(googletest)

set(UT_CPP_SOURCES main_test.cc)
add_executable(${PROJECT_NAME} ${UT_CPP_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE gtest gtest_main gmock gmock_main)