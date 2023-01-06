#pragma once
#include "Component.h"
#include "Math/MathStructs.h"

class TransformComponent : public Component {
public:
	TransformComponent(std::unordered_map<std::string, Component*>* components);
	~TransformComponent() override;
	void SetPosition(const Vector3d& pos);
	void SetRotation(const Vector3d& rot);
	void SetScale(const Vector3d& scale);
	virtual void Update() override;
private:
	Vector3d position;
	Vector3d rotation;
	Vector3d scale;
};