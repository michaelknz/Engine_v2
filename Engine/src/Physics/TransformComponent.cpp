#include "TransformComponent.h"

TransformComponent::TransformComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components), position(), rotation(), scale()
{

}

TransformComponent::~TransformComponent()
{

}

void TransformComponent::SetPosition(const Vector3f& pos)
{
	position = pos;
}

void TransformComponent::SetRotation(const Vector3f& rot)
{
	rotation = rot;
}

void TransformComponent::SetScale(const Vector3f& scale)
{
	this->scale = scale;
}

void TransformComponent::Update()
{

}