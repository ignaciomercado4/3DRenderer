#version 430 core

in vec4 vertexColor;
out vec4 FragColor;

void main(void) 
{
    FragColor = vertexColor;
}