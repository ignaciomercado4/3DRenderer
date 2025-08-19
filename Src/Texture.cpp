////////////////////
// FILE: Texture.cpp //
////////////////////

//////////////
// INCLUDES //
//////////////
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "Texture.hpp"
#include "Debug.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

unsigned int Texture::loadPNG(std::string fileName)
{
    std::string path = "../Resources/Textures/" + fileName + ".png";

    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (!data)
    {
        std::cerr << "Error while loading texture at path: " << path << "\n";
        return 0;
    }

    GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    return ID;
}

unsigned int Texture::loadCubemap()
{
    std::vector<std::string> faces{
        "../Resources/Textures/Skybox/right.jpg",
        "../Resources/Textures/Skybox/left.jpg",
        "../Resources/Textures/Skybox/bottom.jpg",
        "../Resources/Textures/Skybox/top.jpg",
        "../Resources/Textures/Skybox/front.jpg",
        "../Resources/Textures/Skybox/back.jpg",
    };
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, ID);

    int width, height, nrChannels;

    for (int i = 0; i < faces.size(); i++)
    {
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

        if (!data)
        {
            std::cerr << "Error loading cubemap texture at: " << faces[i] << std::endl;
            stbi_image_free(data);
            return 0;
        }
        else
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return ID;
}