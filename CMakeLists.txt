cmake_minimum_required(VERSION 3.21)
project(Perceptron)

set(CMAKE_CXX_STANDARD 17)

add_executable(Perceptron Source/main.cpp Header/Algorithm.h Header/Node.h Source/Algorithm.cpp Source/Node.cpp Header/Perceptron.h Source/Perceptron.cpp Source/CSVRow.cpp)
