#include "vbo.h"
#include "vao.h"
#include "layout.h"

VAO::VAO(VBO &vbo, const VertexLayout &layout)
{
    glGenVertexArrays(1, &ID);
    glBindVertexArray(ID);
    vbo.bind();

    for (const auto& attr : layout.attributes) 
    {
        glVertexAttribPointer(
            attr.index, 
            attr.size, 
            attr.type, 
            GL_FALSE, 
            layout.stride, // Use the dynamically calculated stride
            (void*)(uintptr_t)attr.offset
        );
        glEnableVertexAttribArray(attr.index);
    }

    glBindVertexArray(0);
}

void VAO::bind()
{
    glBindVertexArray(ID);
}
