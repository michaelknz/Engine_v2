#pragma once
#include <Glad/glad.h>
#include <vector>

class Mesh {
public:
	Mesh(GLenum prim, unsigned int vert_col);
	~Mesh();
	void SetVertexContent(const std::vector<float>& vertices, unsigned int index);
	void Draw();
private:
	GLuint vao;
	std::vector<GLuint> vbos;
	unsigned int vertex_col;
	GLenum primitive;
};