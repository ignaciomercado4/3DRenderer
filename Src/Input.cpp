/////////////////////
// FILE: Input.cpp //
/////////////////////

//////////////
// INCLUDES //
//////////////
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Input.hpp"
#include "Window.hpp"
#include "Camera.hpp"

void Input::updateKeyboard(Camera &camera, Window window)
{
    float speed = 0.125f;

    if (glfwGetKey(window.getWindowPointer(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        window.setWindowShouldClose(true);
    }
    if (glfwGetKey(window.getWindowPointer(), GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.moveForward(speed);
    }
    if (glfwGetKey(window.getWindowPointer(), GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.moveBackward(speed);
    }
    if (glfwGetKey(window.getWindowPointer(), GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.moveLeft(speed);
    }
    if (glfwGetKey(window.getWindowPointer(), GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.moveRight(speed);
    }
}