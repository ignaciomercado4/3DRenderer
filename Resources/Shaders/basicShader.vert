#version 430 core

layout (location=0) in vec3 vertexPosition;

uniform mat4 u_Transform;
out vec4 vertexColor;

void main(void)
{
    gl_Position = u_Transform * vec4(vertexPosition, 1.0f);
    vertexColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);
}