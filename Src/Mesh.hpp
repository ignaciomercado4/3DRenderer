#ifndef MESH_HPP
#define MESH_HPP

#include "Vertex.hpp"
#include "Shader.hpp"
#include <vector>

class Mesh
{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO, VBO, EBO;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

    void draw(Shader &shader);

private:
    void setupMesh();
};

#endif