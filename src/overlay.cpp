#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "overlay.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_opengl3_loader.h"

Overlay::Overlay(GLFWwindow* inputWindow)
{
    window = inputWindow;
}

void Overlay::init()
{

}
