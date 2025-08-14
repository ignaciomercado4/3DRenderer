//////////////////////
// FILE: Window.cpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#include "Window.hpp"

Window::Window(const int windowWidth, const int windowHeight, std::string title)
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(windowWidth, windowHeight, title.c_str(), NULL, NULL);
    if (!window)
    {
        std::cerr << "Error in window creation." << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Error in GLEW init." << std::endl;
        return;
    }

    return;
}

GLFWwindow* Window::getWindowPointer()
{
    return this->window;
}

bool Window::getWindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::setWindowShouldClose(bool val)
{
    return glfwSetWindowShouldClose(window, val);
}

void Window::swapBuffersPollEvents()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
