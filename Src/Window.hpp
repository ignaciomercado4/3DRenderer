//////////////////////
// FILE: Window.hpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.hpp"
#include <iostream>

class Window
{
public:
    GLFWwindow *window;

    Window::Window(const int windowWidth, const int windowHeight, std::string title, Camera* camera);
    GLFWwindow *getWindowPointer();
    bool getWindowShouldClose();
    void setWindowShouldClose(bool val);
    void swapBuffersPollEvents();
};

#endif