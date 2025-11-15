cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

include_directories(include)

add_executable(TicTacToe
    src/main.cpp
    src/ai.cpp
)

