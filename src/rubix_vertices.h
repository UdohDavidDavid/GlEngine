#pragma once
#include "mesh.h"


inline std::vector<Vertex> rubixVertices = {
    // Positions                          // Normals                           // Texture Coords
    // Back Face (Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 0.5f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.5f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 0.5f) },

    // Front Face (Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.5f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 0.5f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.5f) },

    // Left Face (Bottom-Left Quadrant -> U: 0.0 to 0.5, V: 0.0 to 0.5)
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },

    // Right Face (Bottom-Right Quadrant -> U: 0.5 to 1.0, V: 0.0 to 0.5)
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },

    // Bottom Face (Reuses Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },

    // Top Face (Reuses Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }
};

// inline float rubixVertices[] = {
//     // positions          // normals           // texture coords
//     // Back Face (Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
//     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.5f,  0.5f,
//     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.5f,
//     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.5f,  1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.5f,  0.5f,
//
//     // Front Face (Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
//     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,
//     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,
//     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  1.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.5f,  1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,
//
//     // Left Face (Bottom-Left Quadrant -> U: 0.0 to 0.5, V: 0.0 to 0.5)
//     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.5f,
//     -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.5f,  0.5f,
//     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.5f,  0.0f,
//     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.5f,  0.0f,
//     -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.5f,
//
//     // Right Face (Bottom-Right Quadrant -> U: 0.5 to 1.0, V: 0.0 to 0.5)
//     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.5f,
//     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.5f,
//     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.0f,
//     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.5f,  0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.5f,
//
//     // Bottom Face (Reuses Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
//     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.5f,
//     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.5f,  0.5f,
//     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.5f,  1.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.5f,  1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.5f,
//
//     // Top Face (Reuses Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
//     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,
//     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.5f,
//     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f
// };
