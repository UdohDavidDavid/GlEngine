#ifndef MESH_H
#define MESH_H

// #include <assimp/scene.h>
#include <glm/glm.hpp>

// #include "glm/ext/vector_float3.hpp"
#include "shaders.h"

#include <vector>

struct Vertex
{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};



class Mesh
{
    public:
        std::vector<Vertex> vertices;
        glm::vec3 position;

        Mesh(std::vector<Vertex> vertices, glm::vec3 position);
        void Draw(Shader& shader, unsigned int ambience, unsigned int diffuse, unsigned int specular);
        void setPositioon(glm::vec3 position);
    private:
        unsigned int VBO, VAO;
        void setupMesh();
};

#endif
