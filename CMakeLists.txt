cmake_minimum_required(VERSION 2.8)

project(spengine)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++0x -mrecip -ffast-math")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
 ${PROJECT_SOURCE_DIR}/include
 ${PROJECT_SOURCE_DIR}/src/main
 ${PROJECT_SOURCE_DIR}/src/test
)

# build and link test program.
add_executable(project1
  src/main/main.cpp
)
target_link_libraries(project1 spengine)

# build spengine library
add_library(spengine SHARED
  src/main/vec3.cpp
  src/main/particle.cpp
  src/main/render_engine.cpp
  src/main/input_manager.cpp
  src/main/simobject.cpp
  src/main/sim_engine.cpp
  src/main/sim_world.cpp
  src/main/simobject2D.cpp
  src/main/sprite.cpp
  src/main/physics_engine.cpp
  src/main/collision.cpp
)
target_link_libraries(spengine GL)
target_link_libraries(spengine GLEW)
target_link_libraries(spengine GLU)
