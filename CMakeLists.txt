cmake_minimum_required(VERSION 3.10)
project(task_scheduler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)

# Main executable
add_executable(task_scheduler
    src/main.cpp
    src/TaskManager.cpp
    src/UserInterface.cpp
)

if(MSVC)
    target_compile_options(task_scheduler PRIVATE /W4)
else()
    target_compile_options(task_scheduler PRIVATE -Wall -Wextra)
endif()

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(task_scheduler_test
    tests/TaskTest.cpp
    tests/SchedulerTest.cpp
    tests/DateHelperTest.cpp
    src/TaskManager.cpp
)

target_include_directories(task_scheduler_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(task_scheduler_test gtest gtest_main)

if(MSVC)
    target_compile_options(task_scheduler_test PRIVATE /W4)
else()
    target_compile_options(task_scheduler_test PRIVATE -Wall -Wextra)
endif()

enable_testing()
add_test(NAME task_scheduler_test COMMAND task_scheduler_test)

