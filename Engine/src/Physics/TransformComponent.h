#pragma once
#include "Core/Component.h"
#include "Math/MathStructs.h"

class Object;

class TransformComponent : public Component {
public:
	TransformComponent(Object* obj);
	~TransformComponent() override;
	Component* Copy(Object* obj) override;
	void SetPosition(const Vector3f& pos);
	void SetRotation(const Vector3f& rot);
	void SetScale(const Vector3f& scale);
	Vector3f GetPosition();
	Vector3f GetRotation();
	Vector3f GetScale();
	Matrix4x4f GetM();
	virtual void Update() override;
private:
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;
};