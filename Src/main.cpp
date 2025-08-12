////////////////////
// FILE: main.cpp //
////////////////////

//////////////
// INCLUDES //
//////////////
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"

///////////////////
// CONSTS & VARS //
///////////////////
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string TITLE = "I'm a window";

///////////////////
// MAIN FUNCTION //
///////////////////
int main()
{
	Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	Shader basicShader = Shader("basicShader");
	Renderer renderer = Renderer();
	renderer.init();
	basicShader.use();

	while (window.getWindowShouldClose())
	{
		renderer.clear();
		basicShader.use();
		glm::mat4 model(1.0f);
		glm::mat4 view = glm::lookAt(
			glm::vec3(4, 3, 3),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0));
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);
		glm::mat4 transform = projection * view * model;
		basicShader.setMat4(transform, "u_Transform");
		renderer.renderTriangle();
		window.swapBuffersPollEvents();
	}

	glfwTerminate();
	return 0;
}