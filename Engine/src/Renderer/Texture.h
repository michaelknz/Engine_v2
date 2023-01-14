#pragma once
#include <Glad/glad.h>
#include <string>

class Texture {
public:
	Texture();
	~Texture();
	void SetTexture(const std::string& texture_name, GLint interpolate_param);
	void Bind();
	void Unbind();
	std::string GetTexName();
	GLint GetInt();
private:
	std::string tex_name;
	GLint int_param;
	GLuint texture;
	unsigned char* image;
	int weight, height;
};