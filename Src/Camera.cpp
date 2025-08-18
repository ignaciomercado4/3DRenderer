//////////////////////
// FILE: Camera.cpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#include "Camera.hpp"
#include <cmath>

Camera::Camera()
{
    eye = glm::vec3(0.0f, 0.0f, 3.0f);
    viewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
    upVector = glm::vec3(0.0f, 1.0f, 0.0f);

    yaw = -90.0f;  // mirando hacia -Z por defecto
    pitch = 0.0f;
    firstMouse = true;
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(eye, eye + viewDirection, upVector);
}

void Camera::mouseLook(int mouseX, int mouseY)
{
    float sensitivity = 0.1f;

    if (firstMouse)
    {
        lastMouseX = mouseX;
        lastMouseY = mouseY;
        firstMouse = false;
    }

    int xoffset = mouseX - lastMouseX;
    int yoffset = lastMouseY - mouseY;

    lastMouseX = mouseX;
    lastMouseY = mouseY;

    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    viewDirection = glm::normalize(direction);
}

void Camera::moveForward(float speed)
{
    eye += speed * viewDirection;
}

void Camera::moveBackward(float speed)
{
    eye -= speed * viewDirection;
}

void Camera::moveLeft(float speed)
{
    glm::vec3 right = glm::normalize(glm::cross(viewDirection, upVector));
    eye -= right * speed;
}

void Camera::moveRight(float speed)
{
    glm::vec3 right = glm::normalize(glm::cross(viewDirection, upVector));
    eye += right * speed;
}
