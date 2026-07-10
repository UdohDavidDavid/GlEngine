#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "camera.h"

class Window
{
    public:
        bool isInitialized;
        GLFWwindow* window;

        float windowWidth;
        float windowHeight;
        const char* windowTitle;

        Window(float width, float height, const char* title);
        bool Initialize();
        GLFWwindow* getGLFWwindow();
        void addCamera(Camera* camera);
};

#endif
