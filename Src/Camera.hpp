//////////////////////
// FILE: Camera.hpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera();

    glm::mat4 getViewMatrix() const;

    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeft(float speed);
    void moveRight(float speed);
    void mouseLook(int mouseX, int mouseY);

private:
    glm::vec3 eye;           
    glm::vec3 viewDirection; 
    glm::vec3 upVector;      

    float yaw;   
    float pitch; 
    int lastMouseX;
    int lastMouseY;
    bool firstMouse;

    glm::mat4 viewMatrix;
};

#endif
