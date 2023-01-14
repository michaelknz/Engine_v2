#include "Texture.h"
#include <SOIL2.h>

Texture::Texture()
{
	texture = 0;
}

Texture::~Texture()
{
	if (texture != 0) {
		glDeleteTextures(1, &texture);
		texture = 0;
	}
}

void Texture::SetTexture(const std::string& texture_name, GLint interpolate_param)
{
	tex_name = texture_name;
	int_param = interpolate_param;
	if (texture != 0) {
		glDeleteTextures(1, &texture);
		texture = 0;
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, interpolate_param);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, interpolate_param);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	int channels;
	image = SOIL_load_image(texture_name.c_str(), &weight, &height, &channels, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, weight, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateTextureMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void Texture::Unbind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLint Texture::GetInt()
{
	return int_param;
}

std::string Texture::GetTexName()
{
	return tex_name;
}