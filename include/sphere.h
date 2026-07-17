#ifndef SPHERE_H
#define SPHERE_H

#include "mesh.h"
#include <glm/glm.hpp>

class Sphere
{
    public:
        glm::vec3 position;

        float radius;
        float sectorCount;
        float stackCount;
        std::vector<Vertex> circle_vertices;
        std::vector<unsigned int> indices;
        std::vector<unsigned int> lineIndices;

        Sphere(glm::vec3 position, float radius, float sectorCount, float stackCount);
        void Draw(Shader &shader, unsigned int ambience, unsigned int diffuse, unsigned int specular);

    private:
        unsigned int VBO, EBO, VAO;

        void generateVertices();
        void setupMesh();
        void addIndices(unsigned int i1, unsigned int i2, unsigned int i3);
};

#endif
