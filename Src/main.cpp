////////////////////
// FILE: main.cpp //
////////////////////

//////////////
// INCLUDES //
//////////////
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.hpp"


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string TITLE = "I'm a window";

int main()
{
	Window Window(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

	while (Window.getWindowShouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 0.3f, 1.0f);
		Window.swapBuffersPollEvents();
	}
	glfwTerminate();
	return 0;
}