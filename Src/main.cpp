////////////////////
// FILE: main.cpp //
////////////////////

//////////////
// INCLUDES //
//////////////
#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"
#include "Camera.hpp"
#include "Input.hpp"

///////////////////
// CONSTS & VARS //
///////////////////
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string TITLE = "I'm a window";
Camera camera = Camera();

///////////////////
// MAIN FUNCTION //
///////////////////
int main()
{
	Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, &camera);
	Shader basicShader = Shader("basicShader");
	Renderer renderer = Renderer();
	renderer.init();

	Texture texture;
	texture.loadPNG("test");

	///////////////
	// MAIN LOOP //
	///////////////
	while (!window.getWindowShouldClose())
	{
		renderer.clear();
		Input::updateKeyboard(camera, window);
		glm::mat4 model(1.0f);
		glm::mat4 view = camera.getViewMatrix();
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);

		model = glm::translate(model, glm::vec3(0,0,-3));

		glm::mat4 transform = projection * view * model;

		renderer.renderCube(basicShader, transform, texture);
		window.swapBuffersPollEvents();
	}

	glfwTerminate();
	return 0;
}
