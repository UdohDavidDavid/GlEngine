#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "mesh.h"


inline std::vector<Vertex> vertices = {
    // Positions                          // Normals                           // Texture Coords
    // Back Face
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },
    // { {-0.5, -0.5, -0.5},      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(0.0f,  0.0f, -1.0f),      glm::vec2(0.0f, 0.0f) },

    // Front Face
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(0.0f,  0.0f,  1.0f),      glm::vec2(0.0f, 0.0f) },

    // Left Face
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3(-1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },

    // Right Face
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 1.0f,  0.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },

    // Bottom Face
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f,  0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f, -0.5f, -0.5f),      glm::vec3( 0.0f, -1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },

    // Top Face
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 1.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3( 0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(1.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f,  0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 0.0f) },
    { glm::vec3(-0.5f,  0.5f, -0.5f),      glm::vec3( 0.0f,  1.0f,  0.0f),     glm::vec2(0.0f, 1.0f) }
};

inline float lightVertices[] = {
    // Positions          // Normals           // Texture Coords
    // Back Face
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
    0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    // Front Face
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

    // Left Face
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    // Right Face
    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    // Bottom Face
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    // Top Face
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};
