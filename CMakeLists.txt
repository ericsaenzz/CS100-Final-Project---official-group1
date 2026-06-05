cmake_minimum_required(VERSION 3.10)
project(task_scheduler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable
add_executable(task_scheduler_test
    tests/TaskTest.cpp
    tests/SchedulerTest.cpp
    tests/DateHelperTest.cpp
    src/TaskManager.cpp
)

target_link_libraries(task_scheduler_test
    gtest_main
)

add_test(
    NAME TaskSchedulerTests
    COMMAND task_scheduler_test
)
