//////////////////////
// FILE: Shader.cpp //
//////////////////////

//////////////
// INCLUDES //
//////////////
#include "Shader.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>

Shader::Shader(std::string shaderName)
{
    std::string vertexShaderPath = "../Resources/Shaders/" + shaderName + ".vert";
    std::string fragmentShaderPath = "../Resources/Shaders/" + shaderName + ".frag";

    std::string vertexShaderCode;
    std::ifstream vertexShaderStream(vertexShaderPath, std::ios::in);
    if (vertexShaderStream.is_open())
    {
        std::string Line = "";
        while (getline(vertexShaderStream, Line))
            vertexShaderCode += "\n" + Line;
        vertexShaderStream.close();
    }
    else
    {
        std::cerr << "Unable to open: " << vertexShaderPath << std::endl;
        return;
    }

    std::string fragmentShaderCode;
    std::ifstream fragmentShaderStream(fragmentShaderPath, std::ios::in);
    if (fragmentShaderStream.is_open())
    {
        std::string Line = "";
        while (getline(fragmentShaderStream, Line))
            fragmentShaderCode += "\n" + Line;
        fragmentShaderStream.close();
    }
    else
    {
        std::cerr << "Unable to open: " << vertexShaderPath << std::endl;
        return;
    }

    const char *vertexShaderSource_ccp = vertexShaderCode.c_str();
    unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vertexShaderSource_ccp, NULL);
    glCompileShader(vShader);
    checkCompileErrors(vShader, "VERTEX");

    const char *fragmentShaderSource_ccp = fragmentShaderCode.c_str();
    unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fragmentShaderSource_ccp, NULL);
    glCompileShader(fShader);
    checkCompileErrors(fShader, "FRAGMENT");

    ID = glCreateProgram();
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Shader compilation error of type: " << type << "\n"
                      << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Shader linking error of type: " << type << "\n"
                      << infoLog << std::endl;
        }
    }
}

void Shader::setMat4(glm::mat4 &matrix, std::string name)
{
    int location = glGetUniformLocation(ID, name.c_str());

    if (location == -1)
    {
        std::cout << "Uniform type mat4 " << name << " not found." << std::endl;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::setInt(int num, std::string name)
{
    int location = glGetUniformLocation(ID, name.c_str());

    if (location == -1)
    {
        std::cout << "Uniform type int " << name << " not found." << std::endl;
    }
    glUniform1i(location, num);
}