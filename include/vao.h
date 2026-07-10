#ifndef VAO_H
#define VAO_H

#include "vbo.h"
#include "layout.h"

class VAO
{
    public:
        unsigned int ID;
        VAO(VBO &vbo, const VertexLayout &layout);
        void bind();
};

#endif // !VAO_H
