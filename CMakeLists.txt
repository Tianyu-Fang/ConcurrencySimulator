cmake_minimum_required(VERSION 3.29)
project(ConcurrencySimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConcurrencySimulator main.cpp
        Task.cpp
        TaskQueue.cpp
        Worker.cpp
        TaskScheduler.cpp
        Task.h
        TaskQueue.h
        TaskScheduler.h
        Worker.h
)
