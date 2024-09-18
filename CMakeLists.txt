cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cs200-assignment-2 VERSION 1)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(GLEW REQUIRED)

add_compile_options (-fdiagnostics-color=always)
add_compile_options(-Wextra -Wall -Wpedantic -std=c++11)

add_library(MyMesh MyMesh.cpp)
target_link_libraries(MyMesh PRIVATE glm::glm)

add_executable(test MyMeshTest.cpp)
target_link_libraries(test PRIVATE OpenGL cs200-assignment-1 glm::glm SDL2::SDL2 ${GLEW_LIBRARIES})
include_directories(test ${GLEW_INCLUDE_DIRS})

# vim:shiftwidth=2:
