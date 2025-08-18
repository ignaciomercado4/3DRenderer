cmake_minimum_required(VERSION 3.15)

# Toolchain antes del project() para vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/Users/nacho/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(Rendering)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencias de vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

# Archivos fuente
add_executable(Rendering
    src/main.cpp
    src/Window.cpp
    src/Shader.cpp
    src/Renderer.cpp
    src/Texture.cpp
    src/Camera.cpp
    src/Input.cpp
    src/InputCallbacks.cpp
    src/Model.cpp
)

# Incluir carpeta ./Include (donde está stb_image.h)
target_include_directories(Rendering PRIVATE ${CMAKE_SOURCE_DIR}/Include)

# Enlazar librerías
target_link_libraries(Rendering PRIVATE
    glfw
    GLEW::GLEW
    opengl32
    glm::glm
)
