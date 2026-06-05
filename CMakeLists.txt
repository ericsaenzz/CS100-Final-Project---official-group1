cmake_minimum_required(VERSION 3.10)
project(task_scheduler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_scheduler
    main.cpp
    TaskManager.cpp
)

if(MSVC)
    target_compile_options(task_scheduler PRIVATE /W4)
else()
    target_compile_options(task_scheduler PRIVATE -Wall -Wextra)
endif()
