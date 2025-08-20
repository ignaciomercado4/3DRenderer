//////////////////////
// FILE: Shader.cpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <glm/glm.hpp>

class Shader
{
public:
    unsigned int ID;
    Shader() {};
    Shader(std::string shaderName);
    void use();
    void setMat4(glm::mat4 &matrix, std::string name);
    void setInt(int num, std::string name);

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif