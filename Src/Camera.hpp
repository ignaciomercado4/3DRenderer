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

private:
    glm::vec3 eye;
    glm::vec3 viewDirection;
    glm::vec3 upVector;

    // T.T
    glm::mat4 viewMatrix;
};

#endif