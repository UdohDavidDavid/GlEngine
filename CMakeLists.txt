cmake_minimum_required(VERSION 3.10)
project(OpenGLWindow C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Load PkgConfig
find_package(PkgConfig REQUIRED)

# 2. Use pkg-config to locate GLFW3
pkg_check_modules(GLFW REQUIRED glfw3)

# Define include directories so compiler finds glad.h and imgui.h
include_directories(include)
include_directories(../include)
include_directories(include/glm)
include_directories(include/glm/gtc)
include_directories(include/glad)
include_directories(src/imgui)
include_directories(src/imgizmo)

# Gather all source files
# (Explicitly listing files is safer than wildcards in CMake)
set(SOURCES
    src/main.cpp
    src/glad.c
    src/stb_image.cpp
    src/functions.cpp
    src/light.cpp
    src/mesh.cpp
    src/# overlay.cpp
    src/renderer.cpp
    src/shaders.cpp
    src/textures.cpp
    src/vao.cpp
    src/vbo.cpp
    src/camera.cpp
    src/window.cpp
    src/sphere.cpp
    src/model.cpp
    src/imgui/imgui.cpp
    src/imgui/imgui_draw.cpp
    src/imgui/imgui_widgets.cpp
    src/imgui/imgui_tables.cpp
    src/imgui/imgui_demo.cpp
    src/imgui/imgui_impl_glfw.cpp    
    src/imgui/imgui_impl_opengl3.cpp
    src/imgizmo/ImGuizmo.cpp
)

# Define your executable output
add_executable(main ${SOURCES})

add_compile_options(-g)

# Link libraries (GL, glfw, and dl)
target_link_libraries(main GL glfw dl assimp)

# Assuming you have a "shaders" folder and "textures" folder in your project root
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# If you have an assets or textures folder, copy that too:
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create a custom command that runs every time you build your executable
add_custom_command(
    TARGET main  # <- Replace with your actual target name (e.g., MyGame)
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/src/shaders"
    "${CMAKE_CURRENT_BINARY_DIR}/src/shaders"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/src/images"
    "${CMAKE_CURRENT_BINARY_DIR}/src/images"
)
