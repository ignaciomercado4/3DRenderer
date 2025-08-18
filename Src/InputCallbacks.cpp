//////////////////////////////
// FILE: InputCallbacks.cpp //
//////////////////////////////

//////////////
// INCLUDES //
//////////////
#include "InputCallbacks.hpp"
#include "Camera.hpp"

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    Camera* cam = static_cast<Camera*>(glfwGetWindowUserPointer(window));
    if (!cam) return; 

    cam->mouseLook(static_cast<int>(xpos), static_cast<int>(ypos));
}
