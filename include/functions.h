#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "camera.h"
#include "light.h"
#include "mesh.h"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Callback {
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
} // namespace Callback

void clearColors(glm::vec3 *lightColor);
void changeColors(glm::vec3 *lightColor);
bool IsMouseHoveringObject(GLFWwindow *window, glm::vec3 objPos, glm::mat4 view,
                           glm::mat4 proj, float boxSize);
void imgizmo_hover_translate(GLFWwindow *window, glm::vec3 &objPos,
                             glm::mat4 viewMatrix, glm::mat4 projectionMatrix,
                             float box_size);
unsigned int loadTextureFromFile(char const *path);
unsigned int loadTextureFromColor(glm::vec3 color);

float calc_aspect_ratio(float width, float height);

void processInput(GLFWwindow *window, Camera &camera, float deltaTime);

glm::mat4 rotateModel(glm::mat4 &rubixModel, float rotationSpeed,
                      float deltaTime);

std::vector<Vertex> generateCircle();

#endif
