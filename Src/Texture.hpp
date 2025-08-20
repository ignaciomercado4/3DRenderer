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
        Texture() {};
        Texture(std::string fileName) { loadPNG(fileName); };
        unsigned int ID;
        unsigned int loadPNG(std::string fileName);
        unsigned int loadCubemap();
        void bind(unsigned int unit) const;
        void bindCubemap(unsigned int unit) const;
};

#endif