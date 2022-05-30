cmake_minimum_required(VERSION 3.21)
project(Tetris)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES main.cpp
            src/Pieces.cpp
            src/Board.cpp )
                    


add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ./inc)
