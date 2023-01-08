#include "SpriteComponent.h"
#include "Core/CameraComponent.h"
#include "Core/Scene.h"
#include "Core/Object.h"

SpriteComponent::SpriteComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components), mesh(GL_TRIANGLES, 6), shader()
{
	shader.Compile();
	std::vector<float> position = {
		-0.5, -0.5, 0,
		-0.5, 0.5, 0,
		0.5, 0.5, 0,
		-0.5, -0.5, 0,
		0.5, 0.5, 0,
		0.5, -0.5, 0
	};
	mesh.SetVertexContent(position, 0);
	std::vector<float> texture = {
		0.0, 0.0,
		0.0, 1.0,
		1.0, 1.0,
		0.0, 0.0,
		1.0, 1.0,
		1.0, 0.0
	};
	mesh.SetVertexContent(texture, 1);
	camera = Scene::getInstance()->GetCamera()->GetComponent<CameraComponent>("camera");
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::Update()
{
	shader.Bind();
	shader.SendMatrix4x4f(Matrix4x4f(camera->GetVP()), "mvp");
	mesh.Draw();
	shader.Unbind();
}