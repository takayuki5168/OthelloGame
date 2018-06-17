cmake_minimum_required(VERSION 3.0)

project(OthelloGame CXX)

find_package(GLUT)
find_package(OpenGL)

set(CMAKE_CXX_FLAGS "-g -Wall -std=gnu++14")
set(CMAKE_BUILD_TYPE Release)

add_executable(othello-game src/main.cpp)
target_link_libraries(othello-game ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
