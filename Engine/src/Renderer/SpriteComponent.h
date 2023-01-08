#pragma once
#include "Core/Component.h"
#include "Renderer/Shader2D.h"
#include "Renderer/Mesh.h"
#include "Renderer/Texture.h"

class CameraComponent;
class TransformComponent;

class SpriteComponent: public Component {
public:
	SpriteComponent(std::unordered_map<std::string, Component*>* components);
	~SpriteComponent() override;
	virtual void Update() override;
	void SetTexture(const std::string& texture_name, GLint inter_param);
private:
	Shader2D shader;
	Mesh mesh;
	CameraComponent* camera;
	TransformComponent* transform;
	Texture texture;
};