/////////////////////
// FILE: Model.hpp //
/////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <glm/glm.hpp>
#include <iostream>

struct Vertex {
    glm::vec3 position;
    glm::vec2 texCoord;
    glm::vec3 normal;
};

class Model
{
public:
    Model(std::string fileName) {loadOBJ(fileName);};
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    
    void loadOBJ(std::string fileName);
    void printOBJData();

private:
    std::vector<glm::vec3> tempVertices;
    std::vector<glm::vec2> tempUVs;
    std::vector<glm::vec3> tempNormals;
};

#endif