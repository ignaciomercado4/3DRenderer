cmake_minimum_required(VERSION 3.15)
project(Rendering)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/nacho/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(Rendering src/main.cpp
    src/Window.cpp)

target_link_libraries(Rendering PRIVATE glfw GLEW::GLEW opengl32)


