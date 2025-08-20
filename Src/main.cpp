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
#include "ResourceManager.hpp"

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
	Renderer renderer = Renderer();
	renderer.init();
    ResourceManager::init();
	
	Texture skyboxTexture;
	skyboxTexture.loadCubemap();

	///////////////
	// MAIN LOOP //
	///////////////
	while (!window.getWindowShouldClose())
{
    renderer.clear();
    Input::updateKeyboard(camera, window);

    glm::mat4 view = camera.getViewMatrix();
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT,
        0.1f, 100.0f
    );

     ////// MODEL ///////
    Shader& shader = ResourceManager::getShader("basicShader");
    shader.use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0, 0, -3));
    glm::mat4 transform = projection * view * model;

    shader.setMat4(transform, "u_Transform");

    ResourceManager::getTexture("test").bind(0);
    ResourceManager::getModel("Amorph").draw(shader);


    ////// SKYBOX ///////
    Shader& skyboxShader = ResourceManager::getShader("skybox");
    skyboxShader.use();

    glm::mat4 sbView = glm::mat4(glm::mat3(view));
    glm::mat4 sbTransform = projection * sbView;
    skyboxShader.setMat4(sbTransform, "u_Transform");
    skyboxTexture.bindCubemap(0); 
    renderer.renderSkybox(skyboxShader);
   

    window.swapBuffersPollEvents();
}


	glfwTerminate();
	return 0;
}
