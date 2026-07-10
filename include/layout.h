#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>

struct VertexAttribute
{
    unsigned int index;
    int size;          // e.g., 3 for positions, 2 for texture coordinates
    unsigned int type; // e.g., GL_FLOAT
    unsigned int offset;
};

// A helper structure to calculate the total stride of your vertex format
struct VertexLayout
{
    unsigned int stride = 0;
    std::vector<VertexAttribute> attributes;

    void AddAttribute(unsigned int index, int size, unsigned int type, unsigned int typeSize, unsigned int offset) {
        attributes.push_back({index, size, type, offset});
        stride += size * typeSize; // Keeps track of total size per vertex automatically
    }
};

#endif
