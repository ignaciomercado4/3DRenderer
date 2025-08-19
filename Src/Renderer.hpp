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
#include "Model.hpp"

class Renderer
{
public:
    Renderer();
    void init();
    void clear();
    void renderModel(Model model, Shader shader, glm::mat4 transform, Texture texture);
    void renderSkybox(Shader shader, glm::mat4 transform, Texture texture);
private:
    unsigned VAO;
    unsigned VBO;
    unsigned EBO;
};

#endif