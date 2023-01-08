#include "SpriteComponent.h"
#include "Core/CameraComponent.h"
#include "Physics/TransformComponent.h"
#include "Core/Scene.h"
#include "Core/Object.h"

SpriteComponent::SpriteComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components), mesh(GL_TRIANGLES, 6), shader()
{
	texture.SetTexture("res/checkerboard.png", GL_NEAREST);
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
	transform = GetComponent<TransformComponent>("transform");
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::SetTexture(const std::string& texture_name, GLint inter_param)
{
	texture.SetTexture(texture_name, inter_param);
}

void SpriteComponent::Update()
{
	shader.Bind();
	texture.Bind();

	shader.SendMatrix4x4f(camera->GetVP() * transform->GetM(), "mvp");
	shader.Send1i(0, "Texture");

	mesh.Draw();

	texture.Unbind();
	shader.Unbind();
}