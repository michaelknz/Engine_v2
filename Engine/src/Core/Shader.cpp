#include "Shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(const std::string& shader_name, int shader_col) {
	shaders.reserve(shader_col);
	this->shader_name = shader_name;
}

Shader::~Shader() {
	DetachShaders();
	glDeleteProgram(prog);
}

void Shader::Compile() {
	prog = glCreateProgram();
	MakeProg(shader_name);
	AttachShaders(shaders.capacity());
	glLinkProgram(prog);
}

void Shader::Bind() {
	glUseProgram(prog);
}

void Shader::Unbind() {
	glUseProgram(0);
}

std::string Shader::ReadShader(const std::string& filename) {
	std::ifstream file;
	file.open(filename.c_str());
	std::string output;
	while (file.good()) {
		std::string line;
		std::getline(file, line);
		output += line + "\n";
	}
	file.close();
	return output;
}

void Shader::CompileShader(const std::string& text, GLuint type) {
	GLuint Shader;
	Shader = glCreateShader(type);
	const char* p[1];
	int l[1];
	p[0] = text.c_str();
	l[0] = text.size();
	glShaderSource(Shader, 1, p, l);
	glCompileShader(Shader);
	shaders.push_back(Shader);
}

void Shader::MakeProg(const std::string& shader_name) {

}

void Shader::AttachShaders(int shader_col) {
	for (int i = 0; i < shader_col; ++i) {
		glAttachShader(prog, shaders[i]);
	}
}

void Shader::DetachShaders() {
	for (int i = 0; i < shaders.size(); ++i) {
		glDetachShader(prog, shaders[i]);
		glDeleteShader(shaders[i]);
	}
}

void Shader::MakeShader(const std::string& file_name, GLuint type) {
	CompileShader(ReadShader(file_name), type);
}