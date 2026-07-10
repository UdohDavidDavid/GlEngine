#ifndef OVERLAY_H
#define OVERLAY_H


#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Overlay
{
    public:
        GLFWwindow* window;
        Overlay(GLFWwindow* inputWindow);
        void init();
};

#endif // !OVERLAY_H
