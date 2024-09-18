cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Assignment2)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

if(MSVC)
	include(FetchContent)

	FetchContent_Declare(
		glm
		GIT_REPOSITORY	https://github.com/g-truc/glm.git
		GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
	)

	FetchContent_MakeAvailable(glm)

	FetchContent_Declare(
		GLEW
		URL            https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip
	)

	FetchContent_MakeAvailable(GLEW)

	FetchContent_Declare(
		SDL2
		URL            https://github.com/libsdl-org/SDL/releases/download/release-2.30.7/SDL2-2.30.7-win32-x64.zip
	)

	FetchContent_MakeAvailable(glew)
endif()

if(UNIX)
	find_package(glm REQUIRED)
	find_package(GLEW REQUIRED)
	find_package(SDL2 REQUIRED)
endif()

find_package(OpenGL REQUIRED)

# TODO: make sure to update this to reflect the files
add_executable(MeshTest Mesh.cpp Affine.cpp)
target_link_libraries(AffineTest OpenGL glm::glm GLEW SDL2)
