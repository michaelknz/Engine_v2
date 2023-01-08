#include "Mesh.h"

Mesh::Mesh(GLenum prim, unsigned int vert_col)
{
	vertex_col = vert_col;
	primitive = prim;
	glGenVertexArrays(1, &vao);
}

Mesh::~Mesh()
{
	glDeleteBuffers(vbos.size(), &vbos[0]);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::SetVertexContent(const std::vector<float>& vertices, unsigned int index)
{
	GLuint new_vbo;
	glGenBuffers(1, &new_vbo);
	vbos.push_back(new_vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, new_vbo);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(index, vertices.size() / vertex_col, GL_FLOAT, GL_FALSE, (vertices.size() / vertex_col) * sizeof(float), (GLvoid*)(0));
	glEnableVertexAttribArray(index);

	glBindVertexArray(0);

}

void Mesh::Draw()
{
	glBindVertexArray(vao);
	glDrawArrays(primitive, 0, vertex_col);
	glBindVertexArray(0);
}