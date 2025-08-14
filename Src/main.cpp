////////////////////
// FILE: main.cpp //
////////////////////

//////////////
// INCLUDES //
////////////// 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

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

	glm::mat4 model(1.0f);
	glm::mat4 view = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0));
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);
	glm::mat4 transform = projection * view * model;
	Texture texture;
	texture.loadPNG("test");
	GLint numUniforms;
	glGetProgramiv(basicShader.ID, GL_ACTIVE_UNIFORMS, &numUniforms);
	for (int i = 0; i < numUniforms; i++) {
		char name[256];
		glGetActiveUniformName(basicShader.ID, i, sizeof(name), NULL, name);
		std::cout << "Uniform " << i << ": " << name << std::endl;
	}

	while (!window.getWindowShouldClose())
	{
		renderer.clear();
		renderer.renderQuad(basicShader, transform, texture);
		window.swapBuffersPollEvents();
	}

	glfwTerminate();
	return 0;
}
