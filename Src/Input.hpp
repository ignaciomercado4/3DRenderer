/////////////////////
// FILE: Input.hpp //
/////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef INPUT_HPP
#define INPUT_HPP
#include "Camera.hpp"
#include "Window.hpp"

class Input
{
public:
    static void updateKeyboard(Camera &camera, Window window);
};

#endif