#ifndef TEXTURE_H
#define TEXTURE_H

#include "../include/glad/glad.h"
#include "stb_image.h"
#include "glm/glm.hpp"


class Texture
{
    public:
        unsigned int ID;
        unsigned char *data;
        int width, height, nrChannels;
        GLenum format;
        // unsigned char pixelData[];

        Texture(const char* filePath);
        Texture(glm::vec3 color);
        void setParameter(GLenum pname, GLint param);
};

#endif
