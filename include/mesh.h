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

struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};


class Mesh
{
    public:
        std::vector<Vertex> vertices;
        std::vector<Texture> textures;
        std::vector<unsigned int> indices;
        glm::vec3 position;

        Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices, std::vector<Texture> &textures);
        // void Draw(Shader& shader, unsigned int ambience, unsigned int diffuse, unsigned int specular);
        void Draw(Shader& shader);
        void setPositioon(glm::vec3 position);
    private:
        unsigned int VBO, EBO, VAO;
        void setupMesh();
};

#endif
