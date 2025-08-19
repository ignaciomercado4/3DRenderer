///////////////////////////////
// FILE: ResourceManager.hpp //
///////////////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP
#include <iostream>
#include "Model.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include <vector>

class ResourceManager
{
public:
    static void loadTexture(std::string fileName);
    static void loadModel(std::string fileName);

private:
    std::vector<std::string, Texture> textures;
    std::vector<std::string, Shader> shaders;
    std::vector<std::string, Model> textures;
};

#endif
