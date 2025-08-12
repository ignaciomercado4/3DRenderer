#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
    GLFWwindow *window;

    Window(const int windowWidth, const int windowHeight, std::string title);
    GLFWwindow *getWindowPointer();
    bool getWindowShouldClose();
    void setWindowShouldClose(bool val);
    void swapBuffersPollEvents();
};

#endif