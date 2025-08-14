#version 430 core

in vec2 textureCoord;
out vec4 FragColor;

uniform sampler2D u_Texture;

void main(void) 
{
    FragColor = texture(u_Texture, textureCoord);
}
