#ifndef SHADER_H
#define SHADER_H

#include "../include/glad/glad.h" // include glad to get all the required OpenGL headers
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
  
#include <string>
#include <iostream>
  

class Shader
{
public:
    unsigned int ID;
  
    // Only put the declarations here
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string &name, float value1, float value2, float value3) const;
    void setMVP(glm::mat4 &model, glm::mat4 &view, glm::mat4 &projection);
};
  
#endif
