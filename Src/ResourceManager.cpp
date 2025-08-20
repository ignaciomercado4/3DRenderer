///////////////////////////////
// FILE: ResourceManager.cpp //
///////////////////////////////

//////////////
// INCLUDES //
//////////////
#include "ResourceManager.hpp"
#include "Model.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include <filesystem>

std::map<std::string, Texture> ResourceManager::textures = {};
std::map<std::string, Shader> ResourceManager::shaders = {};
std::map<std::string, Model> ResourceManager::models = {};

Texture &ResourceManager::loadTexture(std::string name, std::string fileName)
{
    Texture texture;
    texture.loadPNG(fileName);
    textures[name] = texture;
    return textures[name];
}

Shader &ResourceManager::loadShader(std::string name, std::string fileName)
{
    Shader shader(fileName);
    shaders[name] = shader;
    return shaders[name];
}

Model &ResourceManager::loadModel(std::string name, std::string fileName)
{
    Model model(fileName);
    models[name] = model;
    return models[name];
}

Texture &ResourceManager::getTexture(std::string name)
{
    try
    {
        return textures.at(name);
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "ResourceManager texture " << name << " not loaded." << std::endl;
        throw;
    }
}

Shader &ResourceManager::getShader(std::string name)
{
    try
    {
        return shaders.at(name);
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "ResourceManager shader " << name << " not loaded." << std::endl;
        throw;
    }
}

Model &ResourceManager::getModel(std::string name)
{
    try
    {
        return models.at(name);
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "ResourceManager model " << name << " not loaded." << std::endl;
        throw;
    }
}

void ResourceManager::init()
{
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    std::string texturesPath = "../Resources/Textures/";
    std::string shadersPath = "../Resources/Shaders/";
    std::string modelsPath = "../Resources/Models/";

    for (const auto &dirEntry : recursive_directory_iterator(texturesPath))
    {
        if (dirEntry.is_regular_file())
        {
            if (dirEntry.path().string().find("Skybox") != std::string::npos)
            {
                continue;
            }
            else
            {
                std::string fileName = dirEntry.path().stem().string();
                ResourceManager::loadTexture(fileName, fileName);
                std::cout << "ResourceManager: Loaded texture at: " + dirEntry.path().string() << " successfully" << std::endl;
            }
        }
    }
    for (const auto &dirEntry : recursive_directory_iterator(shadersPath))
    {
        if (dirEntry.is_regular_file())
        {
            std::string fileName = dirEntry.path().stem().string();
            ResourceManager::loadShader(fileName, fileName);
            std::cout << "ResourceManager: Loaded shader at: " + dirEntry.path().string() << " successfully" << std::endl;
        }
    }
    for (const auto &dirEntry : recursive_directory_iterator(modelsPath))
    {
        if (dirEntry.is_regular_file())
        {
            std::string fileName = dirEntry.path().stem().string();
            ResourceManager::loadModel(fileName, fileName);
            std::cout << "ResourceManager: Loaded model at: " + dirEntry.path().string() << " successfully" << std::endl;
        }
    }
}

void ResourceManager::clear()
{
    textures.clear();
    shaders.clear();
    models.clear();
}