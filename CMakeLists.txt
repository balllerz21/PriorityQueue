cmake_minimum_required(VERSION 3.23)
project(Project4)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip)

FetchContent_MakeAvailable(googletest)

add_executable(Project4 tests.cpp priorityqueue.h)
target_link_libraries(Project4 gtest_main)


