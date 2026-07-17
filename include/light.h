#ifndef LIGHT_H
#define LIGHT_H

#include "shaders.h"
#include <glm/glm.hpp>
#include "camera.h"
#include <vector>

typedef struct
{
    float constant;
    float linear;
    float quadratic;
} Attenuation;


class Pointlight
{
    public:
        glm::vec3 color;

        glm::vec3 position;

        Attenuation attenuation;
        glm::vec3 ambience;
        glm::vec3 diffuse;
        glm::vec3 specular;
        Pointlight(glm::vec3 position, glm::vec3 color, Attenuation attenuation);
        void update_uniforms(Shader &shader);
};

class Dirlight
{
    public:
        glm::vec3 color;

        glm::vec3 direction;

        glm::vec3 diffuseColor;
        glm::vec3 ambientColor;
        glm::vec3 specular;

        Dirlight(glm::vec3 color, glm::vec3 direction);
        void update_uniforms(Shader &shader);
};

// class Pointlight
// {
//     public:
//         glm::vec3 diffuseColor;
//         glm::vec3 ambientColor;
//
//         Pointlight(glm::vec3 color, std::vector<glm::vec3> position, Shader &shader, Camera &camera);
// };

#endif
