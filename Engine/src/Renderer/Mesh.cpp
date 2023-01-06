#include "Mesh.h"

Mesh::Mesh(GLenum prim, unsigned int vert_col)
{
	vertex_col = vert_col;
	primitive = prim;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::SetVertexContent(const std::vector<double>& vertices, unsigned int index)
{
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(double), &vertices[0], GL_STATIC_DRAW);

	glVertexAttribPointer(index, vertices.size() / vertex_col, GL_DOUBLE, GL_FALSE, (vertices.size() / vertex_col) * sizeof(double), (GLvoid*)(0));
	glEnableVertexAttribArray(index);

}

void Mesh::Draw()
{
	glBindVertexArray(vao);
	glDrawArrays(primitive, 0, vertex_col);
	glBindVertexArray(0);
}