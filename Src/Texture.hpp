////////////////////
// FILE: Texture.hpp //
////////////////////

//////////////
// INCLUDES //
////////////// 
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>
#include <vector>

class Texture
{
    public:
        unsigned int ID;
        unsigned int loadPNG(std::string fileName);
        unsigned int loadCubemap();
};

#endif