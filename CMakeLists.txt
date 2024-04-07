cmake_minimum_required(VERSION 3.5)

project(Dimka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Dimka ./src/main.cpp ./headers/person.h ./src/person.cpp ./headers/strings.h ./src/strings.cpp
    ./headers/gunslinger.h ./src/gunslinger.cpp ./headers/pokerplayer.h ./src/pokerplayer.cpp
    ./headers/card.h ./headers/baddude.h ./src/baddude.cpp)
