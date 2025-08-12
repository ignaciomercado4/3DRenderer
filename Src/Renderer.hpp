#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.hpp"

class Renderer
{
public:
    Renderer();
    void init();
    void clear();
    void renderTriangle();
};

#endif