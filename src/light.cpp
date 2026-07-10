#include "glad/glad.h"
#include <glm/glm.hpp>
#include "light.h"
#include "settings.h"
#include "shaders.h"


Dirlight::Dirlight(glm::vec3 color, glm::vec3 direction)
{
    this->direction = direction;
    this->color = color;
    this->diffuseColor = this->color   * glm::vec3(Settings::DiffuseIntensity); 
    this->ambientColor = this->diffuseColor * glm::vec3(Settings::AmbienceIntensity);
}
void Dirlight::update_uniforms(Shader &shader)
{
    this->diffuseColor = this->color   * glm::vec3(Settings::DiffuseIntensity); 
    this->ambientColor = this->diffuseColor * glm::vec3(Settings::AmbienceIntensity);
    glUniform3fv(glGetUniformLocation(shader.ID, "dirLight.diffuse"), 1, glm::value_ptr(diffuseColor));
    glUniform3fv(glGetUniformLocation(shader.ID, "dirLight.ambient"), 1, glm::value_ptr(ambientColor));
    glUniform3fv(glGetUniformLocation(shader.ID, "dirLight.direction"), 1, glm::value_ptr(direction));
    glUniform3fv(glGetUniformLocation(shader.ID, "dirLight.specular"), 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));
}

Pointlight::Pointlight(glm::vec3 position, glm::vec3 color, Attenuation attenuation)
{
    this->color = color;
    this->diffuse = this->color * glm::vec3(Settings::DiffuseIntensity);
    this->ambience = this->diffuse * glm::vec3(Settings::AmbienceIntensity);
    this->position = position;
    this->attenuation = attenuation;

}

void Pointlight::update_uniforms(Shader &shader)
{
    this->diffuse = this->color * glm::vec3(Settings::DiffuseIntensity);
    this->ambience = this->diffuse * glm::vec3(Settings::AmbienceIntensity);
    glUniform3fv(glGetUniformLocation(shader.ID, "pointLight.position"), 1, glm::value_ptr(this->position));

    glUniform3fv(glGetUniformLocation(shader.ID, "pointLight.diffuse"), 1, glm::value_ptr(this->diffuse));
    glUniform3fv(glGetUniformLocation(shader.ID, "pointLight.ambient"), 1, glm::value_ptr(this->ambience));
    glUniform3fv(glGetUniformLocation(shader.ID, "pointLight.specular"), 1, glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));

    shader.setFloat("pointLight.constant", this->attenuation.constant);
    shader.setFloat("pointLight.linear", this->attenuation.linear);
    shader.setFloat("pointLight.quadratic", this->attenuation.quadratic);
}
// Pointlight::Pointlight(glm::vec3 color, std::vector<glm::vec3> position, Shader &shader, Camera &camera)
// {
//     diffuseColor = color   * glm::vec3(Settings::DiffuseIntensity); 
//     ambientColor = diffuseColor * glm::vec3(Settings::AmbienceIntensity);
//
//     for (int i = 0; i < position.size(); ++i)
//     {
//         int 
//     }
// }
