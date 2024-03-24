cmake_minimum_required(VERSION 3.5)

project(Dimka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Dimka ./src/main.cpp ./headers/queueTp.h ./src/strings.cpp ./headers/strings.h
    ./headers/workermi.h ./src/workermi.cpp)
