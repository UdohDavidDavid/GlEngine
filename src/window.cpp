#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "stdio.h"
#include "window.h"
#include "settings.h"
#include "camera.h"
#include "functions.h"

Window::Window(float width, float height, const char* title)
{
    windowWidth = width;
    windowHeight = height;
    windowTitle = title;
}

bool Window::Initialize()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, Settings::MSAASamples); // 4x MSAA is the sweet spot for performance/quality
                                                         //
    // Create window
    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        isInitialized = false;
        glfwTerminate();
        return false;
    }

    isInitialized = true;
    glfwMakeContextCurrent(window);

    // Add this line to turn off VSync (0 = off, 1 = on)
    glfwSwapInterval(Settings::Vsync ? 1 : 0);
    glfwSetFramebufferSizeCallback(window, Callback::framebuffer_size_callback);
    glfwSetCursorPosCallback(window, Callback::mouse_callback);
    glfwSetScrollCallback(window, Callback::scroll_callback);
    return true;
}

GLFWwindow* Window::getGLFWwindow()
{
    return window;
}

void Window::addCamera(Camera* camera)
{
    glfwSetWindowUserPointer(window, camera);
}
