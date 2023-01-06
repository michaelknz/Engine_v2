#pragma once
#include "Core/Component.h"
#include "Renderer/Shader2D.h"
#include "Renderer/Mesh.h"

class SpriteComponent: public Component {
public:
	SpriteComponent(std::unordered_map<std::string, Component*>* components);
	~SpriteComponent() override;
	virtual void Update() override;
private:
	Shader2D shader;
	Mesh mesh;
};