#include "Shader2D.h"
#include <iostream>

Shader2D::Shader2D()
	:Shader("Shader2D", 2)
{

}

Shader2D::~Shader2D()
{

}

void Shader2D::MakeProg(const std::string& shader_name)
{
	MakeShader("shaders/" + shader_name + ".vert", GL_VERTEX_SHADER);
	MakeShader("shaders/" + shader_name + ".frag", GL_FRAGMENT_SHADER);
}