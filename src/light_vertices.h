#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "mesh.h"

//condesed version
inline std::vector<Vertex> vertices = {
    // Back Face
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) }, // 0
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.0f) }, // 1
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) }, // 2
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 1.0f) }, // 3

    // Front Face
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.0f) }, // 4
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 0.0f) }, // 5
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 1.0f) }, // 6
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) }, // 7

    // Left Face
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) }, // 8
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) }, // 9
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }, // 10
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) }, // 11

    // Right Face
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) }, // 12
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) }, // 13
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }, // 14
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) }, // 15

    // Bottom Face
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }, // 16
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) }, // 17
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) }, // 18
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) }, // 19

    // Top Face
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }, // 20
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) }, // 21
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) }, // 22
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) }  // 23
};

inline std::vector<unsigned int> indices = {
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
// inline std::vector<Vertex> vertices = {
//     // Positions                          // Normals                           // Texture Coords
//     // Back Face
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },
//     // { {-0.5, -0.5, -0.5},      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },
//
//     // Front Face
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 1.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.0f) },
//
//     // Left Face
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//
//     // Right Face
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//
//     // Bottom Face
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
//     { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//
//     // Top Face
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
//     { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
//     { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }
// };

// inline float lightVertices[] = {
//     // Positions          // Normals           // Texture Coords
//     // Back Face
//     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
//
//     // Front Face
//     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
//
//     // Left Face
//     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//     // Right Face
//     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
//
//     // Bottom Face
//     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
//
//     // Top Face
//     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
// };
