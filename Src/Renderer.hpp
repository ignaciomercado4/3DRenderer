////////////////////////
// FILE: Renderer.hpp //
////////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef RENDER_HPP
#define RENDER_HPP

#include "Shader.hpp"
#include "Texture.hpp"

class Renderer
{
public:
    Renderer();
    void init();
    void clear();void Renderer::renderQuad(Shader shader, glm::mat4 transform, Texture texture);
};

#endif