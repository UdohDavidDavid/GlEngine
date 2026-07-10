#include "circle_vertices.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <glm/ext/matrix_clip_space.hpp>
#include <math.h>
#include <string>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "settings.h"
#include "shaders.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb_image.h"
#include "camera.h"
#include "light_vertices.h"
#include "rubix_vertices.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "materials.h"
#include "window.h"
#include "renderer.h"
#include "functions.h"
#include "assets.h"
#include "mesh.h"
#include "scene.h"
#include "light.h"
#include "light_vertices.h"
#include <iostream>
#include <vector>


int main(int argc, char **argv) {

    std::cout << "Here" << std::endl;

    Window window(Settings::WindowWidth, Settings::WindowHeight, Settings::WindowTitle);
    if (!window.Initialize()) return -1;

    Renderer renderer;
    if (!renderer.init()) return -1;


    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window.getGLFWwindow(), true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    Camera camera;
    window.addCamera(&camera);

    // Create Shader
    Shader shader("./shaders/steelVertex.glsl", "./shaders/steelFragment.glsl");
    Shader lightingShader("./shaders/lightVertex.glsl", "./shaders/lightFragment.glsl");
    // Shader rubixShader("./shaders/rubixVertex.glsl", "./shaders/rubixFragment.glsl");
    // Shader steelShader("./shaders/steelVertex.glsl", "./shaders/steelFragment.glsl");

    
    unsigned int rubix = loadTextureFromFile("./images/rubiks_cube_41_90_diffuse.jpg");
    unsigned int rubix_specular = loadTextureFromFile("./images/rubix_specular_map.png");

    unsigned int steelContainer = loadTextureFromFile("./images/container2.png");
    unsigned int steelContainerSpecular = loadTextureFromFile("./images/container2_specular.png");

    unsigned int glowstone = loadTextureFromFile("./images/glowstone.png");
    unsigned int glowstoneSpecular = loadTextureFromColor(glm::vec3(1.0f, 1.0f, 1.0f));



    std::vector<unsigned int> materialTextureAmbienceID;
    materialTextureAmbienceID.reserve(24);
    std::vector<unsigned int> materialTextureDiffuseID;
    materialTextureDiffuseID.reserve(24);
    std::vector<unsigned int> materialTextureSpecularID;
    materialTextureSpecularID.reserve(24);

    for (int i = 0; i < 24; ++i)
    {
        materialTextureAmbienceID.push_back(loadTextureFromColor(materialValues[i].ambient));

        materialTextureDiffuseID.push_back(loadTextureFromColor(materialValues[i].diffuse));

        materialTextureSpecularID.push_back(loadTextureFromColor(materialValues[i].specular));
    }

    std::vector<Vertex> circle_vertices = generateCircle();
    for (int i = 0; i < circle_vertices.size(); ++i)
    {
        std::cout << circle_vertices[i].Position.x << " " << circle_vertices[i].Position.y << " " << circle_vertices[i].Position.z << " " << circle_vertices[i].Normal.x << " " << circle_vertices[i].Normal.y << " " << circle_vertices[i].Normal.z << " " << circle_vertices[i].TexCoords.x << " " << circle_vertices[i].TexCoords.y << " " << std::endl;
    }
    std::cout << circle_vertices.size() << std::endl;


    // glm::vec3 lightDir(-0.2f, -1.0f, -0.3f);
    glm::vec3 lightDir(3.0f, 2.0f, -10.0f);
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    Dirlight dirlight(lightColor, lightDir);

    Attenuation attenuatioon[] = 
    {
        {1.0f, 0.045f, 0.0075},     // 100m
    };

    glm::vec3 torch_position(-2.5f, 3.0f, 13.0f);
    glm::vec3 torch_color(1.0f, 1.0f, 1.0f);
    Pointlight torch(torch_position, torch_color, attenuatioon[0]);


    // Create Meshes
    Mesh torchMesh(vertices, torch.position);
    Mesh rubixMesh(circle_vertices, glm::vec3(-5.0f, 0.0f, 6.0f));
    Mesh containerMesh(vertices, containerPositions[0]);
    Mesh materialMesh(vertices, cubePositions[0]);

    
    float deltaTime = 0.0f;	// Time between current frame and last frame
    float lastFrame = 0.0f; // Time of last frame


    // Render loop
    while(!glfwWindowShouldClose(window.getGLFWwindow()))
    {
        glfwPollEvents();

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;  

        float fps = 1.0f / deltaTime;

        processInput(window.getGLFWwindow(), camera, deltaTime);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        // ImGui::ShowDemoWindow();
        // Create your GUI window
        ImGui::Begin("Debug");
        // ImGui::Text(std::to_string(1.0f / deltaTime).c_str());
        ImGui::Text("FPS: %.1f | Camera Pos: X: %.2f | Y: %.2f | Z: %.2f", 1.0f / deltaTime, camera.Position.x, camera.Position.y, camera.Position.z);
        ImGui::ColorEdit3("clear color", (float*)&torch.color); // Edit 3 floats representing a color
                                                               // This creates a dedicated color picker/slider row
        ImGui::ColorEdit4("Background Color", &Settings::background[0]);
        if (ImGui::Button("Clear SkyBox")) {
            Settings::background[0] = 0.098f;
            Settings::background[1] = 0.098f;
            Settings::background[2] = 0.098f;
        }

        // Edit all 3 components (X, Y, Z) of the light position at once
        ImGui::SliderFloat3("Light Position", &torch.position.x, -15.0f, 15.0f);
        ImGui::SliderFloat3("Light Direction", &dirlight.direction.x, -15.0f, 15.0f);
        ImGui::SliderFloat3("Rubix Position", &rubixMesh.position.x, -15.0f, 15.0f);

        static bool isAnimated = false;
        ImGui::Checkbox("Animate Color", &isAnimated);
        if (isAnimated)
        {
            changeColors(&torch.color);
        }
        if (ImGui::Button("Clear Color"))
            clearColors(&lightColor);

        static bool isRotating = true;
        ImGui::Checkbox("Rotate Cube", &isRotating);

        ImGui::SliderFloat("ambience", &Settings::AmbienceIntensity, 0.0f, 1.0f);
        if (ImGui::Button("Default Ambience"))
            Settings::AmbienceIntensity = 0.1f;
        ImGui::SliderFloat("diffuse", &Settings::DiffuseIntensity, 0.0f, 1.0f);
        if (ImGui::Button("Default diffuse"))
            Settings::DiffuseIntensity = 0.5f;

        ImGui::End();


        int width, height;
        glfwGetFramebufferSize(window.getGLFWwindow(), &width, &height);
        float aspectRatio = calc_aspect_ratio(width, height);


        renderer.draw(Settings::background);
        camera.updateViewPos(shader);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Draw in wireframe mode

        shader.use();

        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 projection;
        projection = glm::perspective(glm::radians(Settings::FOV), aspectRatio, 0.1f, 100.0f);
        glm::mat4 view;
        view = camera.GetViewMatrix();
        shader.setMVP(model, view, projection);

        dirlight.update_uniforms(shader);

        //////////////////////////////
        torch.update_uniforms(shader);

        torchMesh.position = torch.position;
        glm::mat4 torchModel = glm::mat4(1.0f);
        torchModel = glm::translate(torchModel, torchMesh.position);
        torchModel = glm::scale(torchModel, glm::vec3(0.2f));

        lightingShader.use();

        lightingShader.setMVP(torchModel, view, projection);
        lightingShader.setFloat("material.shininess", 0.6);
        glUniform3fv(glGetUniformLocation(lightingShader.ID, "lightColor"), 1, glm::value_ptr(torch.color));
        torchMesh.Draw(lightingShader, glowstone, glowstone, glowstoneSpecular);


        shader.use();

        glm::mat4 rubixModel = glm::mat4(1.0f);
        rubixModel = glm::translate(rubixModel, rubixMesh.position);
        if (isRotating) rubixModel = rotateModel(rubixModel, 2.5f, deltaTime);

        shader.setMVP(rubixModel, view, projection);
        shader.setFloat("material.shininess", 0.6);
        rubixMesh.Draw(shader, rubix, rubix, rubix_specular);

        for (int i = 0; i < 11; ++i)
        {
            containerMesh.position = containerPositions[i];
            glm::mat4 containerModel = glm::mat4(1.0f);
            float angle = 20.0f * i;
            containerModel = glm::translate(containerModel, containerMesh.position);
            containerModel = glm::rotate(containerModel, angle, glm::vec3(0.4f, 0.2f, 1.0f));
            shader.setMVP(containerModel, view, projection);
            shader.setFloat("material.shininess", 0.6);
            containerMesh.Draw(shader, steelContainer, steelContainer, steelContainerSpecular);
        }

        for (int i = 0; i < 24; ++i)
        {
            materialMesh.position = cubePositions[i];
            glm::mat4 materialModel = glm::mat4(1.0f);
            materialModel = glm::translate(materialModel, materialMesh.position);
            shader.setMVP(materialModel, view, projection);
            float materialShininess = materialValues[i].shininess;
            shader.setFloat("material.shininess", materialShininess);
            materialMesh.Draw(shader, materialTextureAmbienceID[i], materialTextureDiffuseID[i], materialTextureSpecularID[i]);
        }

        // Rendering
        ImGui::Render();
        // Render ImGui data on top of your scene
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window.getGLFWwindow());
    }

    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    return 0;
}

