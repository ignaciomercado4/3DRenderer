/////////////////////
// FILE: Model.hpp //
/////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef MODEL_HPP
#define MODEL_HPP

#include "Vertex.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include <vector>
#include <glm/glm.hpp>
#include <iostream>

class Model
{
public:
    std::vector<Mesh> meshes;
    Model() {};
    Model(std::string fileName) { loadOBJ(fileName); };
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    void loadOBJ(std::string fileName);
    void printOBJData();
    void draw(Shader &shader);

private:
    std::vector<glm::vec3> tempVertices;
    std::vector<glm::vec2> tempUVs;
    std::vector<glm::vec3> tempNormals;
};

#endif