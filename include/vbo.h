#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"
#include <stddef.h>

class VBO
{
    public:
        unsigned int ID;
        VBO(float* vertices, size_t size);
        void bind();
};


#endif // !VBO_H
