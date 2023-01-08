#pragma once
#include "Core/Component.h"
#include "Math/MathStructs.h"

class TransformComponent : public Component {
public:
	TransformComponent(std::unordered_map<std::string, Component*>* components);
	~TransformComponent() override;
	void SetPosition(const Vector3f& pos);
	void SetRotation(const Vector3f& rot);
	void SetScale(const Vector3f& scale);
	Vector3f GetPosition();
	Vector3f GetRotation();
	Vector3f GetScale();
	virtual void Update() override;
private:
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;
};