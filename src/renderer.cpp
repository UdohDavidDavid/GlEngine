#include "renderer.h"
#include "glad/glad.h"
#include "settings.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

Renderer::Renderer() { isInitialized = false; }

bool Renderer::init()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return false;
    }
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_STENCIL_TEST);

    if (Settings::MSAASamples)
        glEnable(GL_MULTISAMPLE);

    isInitialized = true;
    return true;
}

void Renderer::draw(float *background)
{
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    this->background = background;
    glClearColor(this->background[0], this->background[1], this->background[2],
                 1.0f);
    // glClearColor(0, 0, 0, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // (Settings::wireFrame) ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) :
    // glPolygonMode(GL_POLYGON_SMOOTH, GL_FILL);
    if (Settings::wireFrame)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        glPolygonMode(GL_POLYGON_SMOOTH, GL_FILL);
    }
    if (Settings::MSAASamples)
        glEnable(GL_MULTISAMPLE);
}
