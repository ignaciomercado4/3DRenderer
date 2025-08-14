//////////////////////
// FILE: Camera.cpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#include "Camera.hpp"

Camera::Camera()
{
    eye = glm::vec3(0.0f, 0.0f, 0.0f);
    viewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    upVector = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(eye, viewDirection, upVector);
}

void Camera::moveForward(float speed)
{
    eye.z -= speed;
}

void Camera::moveBackward(float speed)
{
    
    eye.z += speed;
}

void Camera::moveLeft(float speed)
{
}

void Camera::moveRight(float speed)
{
}