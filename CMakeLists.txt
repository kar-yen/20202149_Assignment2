cmake_minimum_required(VERSION 3.17)
project(assignment2 C)

set(CMAKE_C_STANDARD 11)

add_executable(assignment2 main.c initialization.c playGame.c getPossibleMove.c updateBoard.c endGame.c)