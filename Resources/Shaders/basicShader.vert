#version 430 core

layout (location=0) in vec3 l_vertexPosition;
layout (location=1) in vec2 l_textureCoordinate;

uniform mat4 u_Transform;
out vec2 textureCoord; 

void main(void)
{
    gl_Position = u_Transform * vec4(l_vertexPosition, 1.0f);
    textureCoord = l_textureCoordinate; 
}
