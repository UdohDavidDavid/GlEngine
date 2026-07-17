#pragma once
#include "mesh.h"

// Condensed version
inline std::vector<Vertex> rubixVertices = {
    // Back Face (Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 0.5f) }, // 0
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.5f) }, // 1
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) }, // 2
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 1.0f) }, // 3

    // Front Face (Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.5f) }, // 4
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 0.5f) }, // 5
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 1.0f) }, // 6
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) }, // 7

    // Left Face (Bottom-Left Quadrant -> U: 0.0 to 0.5, V: 0.0 to 0.5)
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.5f) }, // 8
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }, // 9
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) }, // 10
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) }, // 11

    // Right Face (Bottom-Right Quadrant -> U: 0.5 to 1.0, V: 0.0 to 0.5)
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.5f) }, // 12
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }, // 13
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) }, // 14
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) }, // 15

    // Bottom Face (Reuses Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.5f) }, // 16
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }, // 17
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) }, // 18
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }, // 19

    // Top Face (Reuses Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }, // 20
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.5f) }, // 21
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) }, // 22
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) }  // 23
};

inline std::vector<unsigned int> rubixIndices = {
    // Back Face
    0, 1, 2,
    2, 3, 0,

    // Front Face
    4, 5, 6,
    6, 7, 4,

    // Left Face
    8, 9, 10,
    10, 11, 8,

    // Right Face
    12, 13, 14,
    14, 15, 12,

    // Bottom Face
    16, 17, 18,
    18, 19, 16,

    // Top Face
    20, 21, 22,
    22, 23, 20
};
// inline std::vector<Vertex> rubixVertices = {
//     // Positions                          // Normals                           // Texture Coords
//     // Back Face (Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 0.5f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.5f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.5f, 0.5f) },
//
//     // Front Face (Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.5f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 0.5f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.5f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.5f) },
//
//     // Left Face (Bottom-Left Quadrant -> U: 0.0 to 0.5, V: 0.0 to 0.5)
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
//
//     // Right Face (Bottom-Right Quadrant -> U: 0.5 to 1.0, V: 0.0 to 0.5)
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.5f, 0.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },
//
//     // Bottom Face (Reuses Top-Left Quadrant -> U: 0.0 to 0.5, V: 0.5 to 1.0)
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.5f) },
//
//     // Top Face (Reuses Top-Right Quadrant -> U: 0.5 to 1.0, V: 0.5 to 1.0)
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.5f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.5f, 0.5f) }
// };

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
