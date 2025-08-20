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
#include <map>

class ResourceManager
{
public:
    static Texture &loadTexture(std::string name, std::string fileName);
    static Shader &loadShader(std::string name, std::string fileName);
    static Model &loadModel(std::string name, std::string fileName);

    static Texture &getTexture(std::string name);
    static Shader &getShader(std::string name);
    static Model &getModel(std::string name);

    static void init();

    static void clear();

private:
    static std::map<std::string, Texture> textures;
    static std::map<std::string, Shader> shaders;
    static std::map<std::string, Model> models;
};

#endif
