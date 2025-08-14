////////////////////
// FILE: Texture.hpp //
////////////////////

//////////////
// INCLUDES //
////////////// 
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>

class Texture
{
    public:
        unsigned int ID;
       unsigned int loadPNG(std::string fileName);
};

#endif