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
private:
	GLuint texture;
	unsigned char* image;
	int weight, height;
};