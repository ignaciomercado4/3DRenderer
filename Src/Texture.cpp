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

unsigned int Texture::loadPNG(std::string fileName)
{
    std::string path = "../Resources/Textures/" + fileName + ".png";

    stbi_set_flip_vertically_on_load(true);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    if (!data) {
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
