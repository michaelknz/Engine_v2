#pragma once
#include <Glad/glad.h>
#include <vector>

class Mesh {
public:
	Mesh(GLenum prim, unsigned int vert_col);
	~Mesh();
	void SetVertexContent(const std::vector<double>& vertices, unsigned int index);
	void Draw();
private:
	GLuint vao;
	GLuint vbo;
	unsigned int vertex_col;
	GLenum primitive;
};