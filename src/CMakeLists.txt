cmake_minimum_required(VERSION 3.10)
project(OpenGLWindow C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define include directories so compiler finds glad.h and imgui.h
include_directories(include)
include_directories(../include)
include_directories(../include/glm)
include_directories(../include/glm/gtc)
include_directories(../include/glad)
include_directories(imgui)
include_directories(imgizmo)

# Gather all source files
# (Explicitly listing files is safer than wildcards in CMake)
set(SOURCES
    main.cpp
    glad.c
    stb_image.cpp
    functions.cpp
    light.cpp
    mesh.cpp
    # overlay.cpp
    renderer.cpp
    shaders.cpp
    textures.cpp
    vao.cpp
    vbo.cpp
    camera.cpp
    window.cpp
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_impl_glfw.cpp    
    imgui/imgui_impl_opengl3.cpp
    imgizmo/ImGuizmo.cpp
)

# Define your executable output
add_executable(main ${SOURCES})

add_compile_options(-g)

# Link libraries (GL, glfw, and dl)
target_link_libraries(main GL glfw dl)

# Assuming you have a "shaders" folder and "textures" folder in your project root
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# If you have an assets or textures folder, copy that too:
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create a custom command that runs every time you build your executable
add_custom_command(
    TARGET main  # <- Replace with your actual target name (e.g., MyGame)
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "${CMAKE_CURRENT_BINARY_DIR}/shaders"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/images"
    "${CMAKE_CURRENT_BINARY_DIR}/images"
)
