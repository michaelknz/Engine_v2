#include "SpriteComponent.h"
#include "Core/CameraComponent.h"
#include "Physics/TransformComponent.h"
#include "Core/Scene.h"
#include "Core/Object.h"

SpriteComponent::SpriteComponent(Object* obj)
	:Component(obj), mesh(GL_TRIANGLES, 6), shader()
{
	comp_name = "sprite";
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

Component* SpriteComponent::Copy(Object* obj)
{
	SpriteComponent* output = new SpriteComponent(object);
	output->comp_name = comp_name;
	output->texture.SetTexture(texture.GetTexName(), texture.GetInt());
	output->object = obj;
	output->transform = output->GetComponent<TransformComponent>("transform");
	return output;
}