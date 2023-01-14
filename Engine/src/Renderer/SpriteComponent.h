#pragma once
#include "Core/Component.h"
#include "Renderer/Shader2D.h"
#include "Renderer/Mesh.h"
#include "Renderer/Texture.h"

class CameraComponent;
class TransformComponent;
class Object;

class SpriteComponent: public Component {
public:
	SpriteComponent(Object* obj);
	~SpriteComponent() override;
	virtual void Update() override;
	void SetTexture(const std::string& texture_name, GLint inter_param);
	Component* Copy(Object* obj) override;
private:
	Shader2D shader;
	Mesh mesh;
	CameraComponent* camera;
	TransformComponent* transform;
	Texture texture;
};