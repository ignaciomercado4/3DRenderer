/////////////////////
// FILE: Model.cpp //
/////////////////////

//////////////
// INCLUDES //
//////////////

#include "Model.hpp"
#include "Mesh.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

void Model::loadOBJ(std::string fileName)
{
    std::string path = "../Resources/Models/" + fileName + ".obj";
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cerr << "Unable to open OBJ file at: " << path << std::endl;
        return;
    }

    std::string line;
    std::vector<std::vector<int>> faceVertexIndices;
    std::vector<std::vector<int>> faceUVIndices;
    std::vector<std::vector<int>> faceNormalIndices;

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        if (line.substr(0, 3) == "vt ")
        {
            glm::vec2 uv;
            std::stringstream ss(line.substr(3));
            ss >> uv.x >> uv.y;
            tempUVs.push_back(uv);
        }
        else if (line.substr(0, 3) == "vn ")
        {
            glm::vec3 normal;
            std::stringstream ss(line.substr(3));
            ss >> normal.x >> normal.y >> normal.z;
            tempNormals.push_back(normal);
        }
        else if (line.substr(0, 2) == "v ")
        {
            glm::vec3 vertex;
            std::stringstream ss(line.substr(2));
            ss >> vertex.x >> vertex.y >> vertex.z;
            tempVertices.push_back(vertex);
        }
        else if (line[0] == 'f')
        {
            std::stringstream ss(line.substr(2));
            std::string vertexStr;
            std::vector<int> vIndices, uvIndices, nIndices;

            while (ss >> vertexStr)
            {
                std::stringstream vs(vertexStr);
                std::string idx;

                if (std::getline(vs, idx, '/') && !idx.empty())
                {
                    vIndices.push_back(std::stoi(idx) - 1);
                }
                if (std::getline(vs, idx, '/') && !idx.empty())
                {
                    uvIndices.push_back(std::stoi(idx) - 1);
                }
                if (std::getline(vs, idx) && !idx.empty())
                {
                    nIndices.push_back(std::stoi(idx) - 1);
                }
            }

            faceVertexIndices.push_back(vIndices);
            faceUVIndices.push_back(uvIndices);
            faceNormalIndices.push_back(nIndices);
        }
    }

    for (int f = 0; f < faceVertexIndices.size(); ++f)
    {
        for (int v = 0; v < faceVertexIndices[f].size(); ++v)
        {
            Vertex vertex;

            vertex.position = tempVertices[faceVertexIndices[f][v]];

            if (!faceUVIndices.empty() && faceUVIndices[f].size() > v)
            {
                vertex.texCoord = tempUVs[faceUVIndices[f][v]];
            }
            else
            {
                vertex.texCoord = glm::vec2(0.0f);
            }

            if (!faceNormalIndices.empty() && faceNormalIndices[f].size() > v)
            {
                vertex.normal = tempNormals[faceNormalIndices[f][v]];
            }
            else
            {
                vertex.normal = glm::vec3(0.0f, 1.0f, 0.0f);
            }

            vertices.push_back(vertex);
            indices.push_back(static_cast<unsigned int>(vertices.size() - 1));
        }
    }
    
    Mesh mesh(vertices, indices);
    meshes.push_back(mesh);

    file.close();
}

void Model::printOBJData()
{
    std::cout << "///// PROCESSED VERTICES /////" << std::endl;
    for (int i = 0; i < vertices.size(); ++i)
    {
        const auto &v = vertices[i];
        std::cout << "Vertex " << i << ":" << std::endl;
        std::cout << "  Position: " << glm::to_string(v.position) << std::endl;
        std::cout << "  TexCoord: " << glm::to_string(v.texCoord) << std::endl;
        std::cout << "  Normal: " << glm::to_string(v.normal) << std::endl;
    }

    std::cout << "///// INDICES /////" << std::endl;
    for (auto i : indices)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void Model::draw(Shader &shader)
{
    for (auto& mesh : meshes) {
        mesh.draw(shader);
    }
}