#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components), mesh(GL_TRIANGLES, 6), shader()
{
	shader.Compile();
	std::vector<double> position = {
		-0.5, -0.5, 0.0,
		-0.5, 0.5, 0.0,
		0.5, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		0.5, 0.5, 0.0,
		0.5, -0.5, 0.0
	};
	mesh.SetVertexContent(position, 0);
	std::vector<double> texture = {
		0.0, 0.0,
		0.0, 1.0,
		1.0, 1.0,
		0.0, 0.0,
		1.0, 1.0,
		1.0, 0.0
	};
	mesh.SetVertexContent(texture, 1);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Update()
{
	shader.Bind();
	mesh.Draw();
	shader.Unbind();
}