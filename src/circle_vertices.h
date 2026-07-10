#ifndef CIRCLE_VERTICES_H
#define CIRCLE_VERTICES_H
#include <cmath>
#include <vector>
#include "mesh.h"
#include <math.h>

// clear memory of prev arrays
// std::vector<float>().swap(vertices);
// std::vector<float>().swap(normals);
// std::vector<float>().swap(texCoords);

inline std::vector<Vertex> generateCircle()
{
    std::vector<Vertex> circle_vertices;
    Vertex vertex;
    float radius = 10.0f;

    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
    float s, t;                                     // vertex texCoord

    float sectorCount = 20.0f;
    float stackCount = 20.0f;

    float PI = (float)M_PI;

    float sectorStep = 2 * PI / sectorCount;
    float stackStep = PI / stackCount;
    float sectorAngle, stackAngle;
    for (int i = 0; i <= stackCount; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= sectorCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            // vertex.push_back(x);
            // vertex.push_back(y);
            // vertex.push_back(z);
            glm::vec3 position(x, y, z);

            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            // vertex.push_back(nx);
            // vertex.push_back(ny);
            // vertex.push_back(nz);
            glm::vec3 normal(nx, ny, nz);

            // vertex tex coord (s, t) range between [0, 1]
            s = (float)j / sectorCount;
            t = (float)i / stackCount;
            // vertex.push_back(s);
            // vertex.push_back(t);
            glm::vec2 texC(s, t);
            vertex.Position  = position;
            vertex.Normal    = normal;
            vertex.TexCoords = texC;

            circle_vertices.push_back(vertex);
        }
    }
    return circle_vertices;
}



#endif
