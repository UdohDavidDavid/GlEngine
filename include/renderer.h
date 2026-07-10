#ifndef OVERLAY_H
#define OVERLAY_H

#include "glad/glad.h"

class Renderer
{
    public:
        bool isInitialized;
        float *background;

        Renderer();
        bool init();
        void draw(float *background);
};

#endif // !OVERLAY_H
