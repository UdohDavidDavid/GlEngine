#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "functions.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "settings.h"
#include "stb_image.h"
#include <iostream>
#include "camera.h"
#include <cmath>
#include "light.h"
#include "shaders.h"
#include "mesh.h"

namespace Callback
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
        static bool firstMouse = true;
        static float lastX = 400.0f;
        static float lastY = 300.0f;
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE))
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            if (firstMouse) {
                lastX = xpos;
                lastY = ypos;
                firstMouse = false;
            }
            float xoffset = xpos - lastX;
            float yoffset = lastY - ypos;
            lastX = xpos;
            lastY = ypos;
            // 1. Retrieve the generic pointer and safely cast it to a Camera pointer
            Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));

            // 2. Make sure it isn't null, then call your function
            if (camera != nullptr)
            {
                camera->ProcessMouseMovement(xoffset, yoffset);
            }
        }
        else
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            firstMouse = true;
        }
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        // 1. Retrieve the generic pointer and safely cast it to a Camera pointer
        Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));

        // 2. Make sure it isn't null, then call your function
        if (camera != nullptr)
        {
            camera->ProcessMouseScroll(static_cast<float>(yoffset));
        }
    }
}


void processInput(GLFWwindow *window, Camera &camera, float deltaTime)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) ==  GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        camera.MovementSpeed = 15.0f;
    } else {
        camera.MovementSpeed = 10.5f;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::UP, deltaTime);
        // cameraPos += cameraSpeed * cameraUp;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.ProcessKeyboard(Camera_Movement::DOWN, deltaTime);
}

void changeColors(glm::vec3 *lightColor)
{
    lightColor->x = sin(glfwGetTime() * 2.0f);
    lightColor->y = sin(glfwGetTime() * 0.7f);
    lightColor->z = sin(glfwGetTime() * 1.3f);
}

void clearColors(glm::vec3 *lightColor) 
{
    lightColor->x = 1.0f;
    lightColor->y = 1.0f;
    lightColor->z = 1.0f;
}



// bool IsMouseHoveringObject(GLFWwindow* window, glm::vec3 objPos, glm::mat4 view, glm::mat4 proj, float boxSize) {
//     // 1. Get mouse position and window size
//     double mouseX, mouseY;
//     glfwGetCursorPos(window, &mouseX, &mouseY);
//
//     int width, height;
//     glfwGetFramebufferSize(window, &width, &height);
//
//     // 2. Convert mouse coordinates to Normalized Device Coordinates (NDC)
//     float x = (2.0f * mouseX) / width - 1.0f;
//     float y = 1.0f - (2.0f * mouseY) / height; // Flip Y axis
//
//     // 3. Create Ray in Clip Space, then unproject to World Space
//     glm::vec4 rayStart_NDC(x, y, -1.0f, 1.0f);
//     glm::vec4 rayEnd_NDC(x, y, 0.0f, 1.0f);
//
//     glm::mat4 invM = glm::inverse(proj * view);
//     glm::vec4 rayStart_World = invM * rayStart_NDC; rayStart_World /= rayStart_World.w;
//     glm::vec4 rayEnd_World   = invM * rayEnd_NDC;   rayEnd_World /= rayEnd_World.w;
//
//     glm::vec3 rayDir = glm::normalize(glm::vec3(rayEnd_World - rayStart_World));
//     glm::vec3 rayOrigin = glm::vec3(rayStart_World);
//
//     // 4. Simple Ray vs AABB (Bounding Box) Intersection Test
//     glm::vec3 boxMin = objPos - glm::vec3(boxSize);
//     glm::vec3 boxMax = objPos + glm::vec3(boxSize);
//
//     float tmin = (boxMin.x - rayOrigin.x) / rayDir.x;
//     float tmax = (boxMax.x - rayOrigin.x) / rayDir.x;
//     if (tmin > tmax) std::swap(tmin, tmax);
//
//     float tymin = (boxMin.y - rayOrigin.y) / rayDir.y;
//     float tymax = (boxMax.y - rayOrigin.y) / rayDir.y;
//     if (tymin > tymax) std::swap(tymin, tymax);
//
//     if ((tmin > tymax) || (tymin > tmax)) return false;
//     if (tymin > tmin) tmin = tymin;
//     if (tymax < tmax) tmax = tymax;
//
//     float tzmin = (boxMin.z - rayOrigin.z) / rayDir.z;
//     float tzmax = (boxMax.z - rayOrigin.z) / rayDir.z;
//     if (tzmin > tzmax) std::swap(tzmin, tzmax);
//
//     if ((tmin > tzmax) || (tzmin > tmax)) return false;
//
//     return true;
// }
//
// void imgizmo_hover_translate(GLFWwindow* window, glm::vec3 &objPos, glm::mat4 viewMatrix, glm::mat4 projectionMatrix, float box_size)
// {
//
//     // Check hover state (0.3f defines the click boundary radius around objPos)
//     bool isHovered = IsMouseHoveringObject(window, objPos, viewMatrix, projectionMatrix, 0.3f);
//     static float timeout = 0.0f;
//     float increase = 1.0f * deltaTime;
//     if (isHovered || ImGuizmo::IsUsing() || ImGuizmo::IsOver() || ImGuizmo::IsViewManipulateHovered())
//     {
//         timeout = 0;
//     }
//     else
//     {
//         timeout += increase;
//     }
//
//     // Show the gizmo ONLY if hovering OR if the user is currently dragging it
//     if (timeout < 1.0f) {
//         glm::mat4 lightModelMatrix = glm::translate(glm::mat4(1.0f), objPos);
//
//         ImGuizmo::Manipulate(
//                 glm::value_ptr(viewMatrix), 
//                 glm::value_ptr(projectionMatrix), 
//                 ImGuizmo::OPERATION::TRANSLATE, 
//                 ImGuizmo::MODE::WORLD, 
//                 glm::value_ptr(lightModelMatrix)
//                 );
//
//         if (ImGuizmo::IsUsing()) {
//             objPos = glm::vec3(lightModelMatrix[3]); // Update your actual light position vector
//         }
//     }
// }

// utility function for loading a 2D texture from file
// ---------------------------------------------------
unsigned int loadTextureFromFile(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    // 2. Check the maximum anisotropy level supported by your GPU
    float maxAnisotropy = 0.0f;
    glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &maxAnisotropy);
    // 3. Apply it to the texture (usually 4.0f or 8.0f is perfect, or use the max)
    if (Settings::AnistrophicFiltering) glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, maxAnisotropy);
    // glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, maxAnisotropy);

    return textureID;
}

unsigned int loadTextureFromColor(glm::vec3 color)
{
    unsigned int ID;
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    // Convert float (0.0f - 1.0f) to unsigned char (0 - 255)
    float alpha = 1.0f;
    unsigned char pixelData[] = {
        static_cast<unsigned char>(color.r * 255.0f),
        static_cast<unsigned char>(color.g * 255.0f),
        static_cast<unsigned char>(color.b * 255.0f),
        static_cast<unsigned char>(alpha * 255.0f)
    };
    // Upload the 1x1 texture data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelData);

    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D, 0);
    return ID;
}


glm::mat4 rotateModel(glm::mat4 &rubixModel, float rotationSpeed, float deltaTime)
{
    static float angle = 0.0f; // Stores the accumulated angle of the light
    rotationSpeed = 0.5f; // Adjust this to make it rotate faster or slow
    angle += rotationSpeed * deltaTime;
    return glm::rotate(rubixModel, (float)glfwGetTime() * 3.0f, glm::vec3(sin(angle), cos(angle), 0.5f));
}

float calc_aspect_ratio(float width, float height)
{
    return width / height;
}

std::vector<Vertex> generateCircle()
{
    std::vector<Vertex> circle_vertices;
    Vertex vertex;
    float radius = 1.0f;

    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
    float s, t;                                     // vertex texCoord

    float sectorCount = 50;
    float stackCount = 50;

    float PI = std::acos(-1.0f);

    float sectorStep = 2 * PI / sectorCount;
    float stackStep = PI / stackCount;
    float sectorAngle, stackAngle;
    for (int i = 0; i <= stackCount; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * std::cosf(stackAngle);             // r * cos(u)
        z = radius * std::sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= sectorCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * std::cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * std::sinf(sectorAngle);             // r * cos(u) * sin(v)
            glm::vec3 position(x, y, z);

            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            glm::vec3 normal(nx, ny, nz);

            // vertex tex coord (s, t) range between [0, 1]
            s = (float)j / sectorCount;
            t = (float)i / stackCount;
            glm::vec2 texC(s, t);

            vertex.Position  = glm::vec3(x, y, z);
            vertex.Normal    = glm::vec3(nx, ny, nz);
            vertex.TexCoords = glm::vec2(s, t);

            circle_vertices.push_back(vertex);
        }
        circle_vertices.push_back(vertex);
    }
    return circle_vertices;
}
