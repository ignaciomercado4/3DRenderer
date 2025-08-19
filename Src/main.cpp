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
#include "Model.hpp"

///////////////////
// CONSTS & VARS //
///////////////////
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;
const std::string TITLE = "I'm a window";
Camera camera = Camera();

///////////////////
// MAIN FUNCTION //
///////////////////
int main()
{
	Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE, &camera);
	Shader basicShader("basicShader");
	Shader skyboxShader("skybox");
	Renderer renderer = Renderer();
	renderer.init();
	Texture texture;
	texture.loadPNG("test");
	Texture skyboxTexture;
	skyboxTexture.loadCubemap();
	Model amorphModel("Amorph");

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
		model = glm::translate(model, glm::vec3(0, 0, -3));
		glm::mat4 transform = projection * view * model;
		renderer.renderModel(amorphModel, basicShader, transform, texture);

		glm::mat4 SBview = glm::mat4(glm::mat3(camera.getViewMatrix()));
		glm::mat4 SBprojection = glm::perspective(glm::radians(45.0f),
												  (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT,
												  0.1f, 100.0f);
		glm::mat4 SBtransform = SBprojection * SBview;
		renderer.renderSkybox(skyboxShader, SBtransform, skyboxTexture);

		window.swapBuffersPollEvents();
	}

	glfwTerminate();
	return 0;
}
