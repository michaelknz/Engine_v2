#pragma once
#include <Glad/glad.h>
#include <string>
#include <vector>

class Shader {
public:
	Shader(const std::string& shader_name, int shader_col);
	virtual ~Shader();
	void Bind();
	void Unbind();
protected:
	void MakeShader(const std::string& file_name, GLuint type);
private:
	std::string ReadShader(const std::string& filename);
	void CompileShader(const std::string& text, GLuint type);
	virtual void MakeProg(const std::string& shader_name);
	void AttachShaders(int shader_col);
	GLuint prog;
	std::vector<GLuint> shaders;
};