cmake_minimum_required(VERSION 3.0)

project(OthelloGame CXX)

# find OpenGL
find_package(GLUT)
find_package(OpenGL)

# Set Configure
set(CMAKE_CXX_FLAGS "-g -Wall -std=gnu++14")
set(CMAKE_BUILD_TYPE Release)

# src/ and include/
file(GLOB_RECURSE SUB_SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/main.cpp)
list(APPEND SOURCES ${SUB_SOURCES})
include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(othello-game ${SOURCES})
target_link_libraries(othello-game
  ${GLUT_LIBRARY}
  ${OPENGL_LIBRARY}
  m)
