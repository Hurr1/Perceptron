cmake_minimum_required(VERSION 3.17)
project(Perceptron)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE RESOURSES_FILES Resourses/*.png)
file(GLOB_RECURSE RESOURSES_FILES Resourses/*.cvs)
file(GLOB_RECURSE RESOURSES_FILES Resourses/*.ttf)

file(GLOB_RECURSE SRC_FILES Source/*.cpp)

add_executable(AI ${SRC_FILES} ${RESOURSES_FILES} Header/TextBox.h Header/Button.h Source/TextBox.cpp)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(AI sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
