#include "CameraComponent.h"

CameraComponent::CameraComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components), width(0), height(0)
{
	fov = 90.0;
	zNear = 0.1;
	zFar = 100.0;
}

CameraComponent::~CameraComponent()
{

}

void CameraComponent::SetSize(int width, int height)
{
	this->width = width;
	this->height = height;
	SetVP();
}

void CameraComponent::SetVP()
{
	VP = MakeP() * MakeV();
}

Matrix4x4f CameraComponent::GetVP()
{
	return VP;
}

Matrix4x4f CameraComponent::MakeP()
{
	Matrix4x4f perspective;
	float aspect = (float)width / (float)height;
	perspective.mas[0] = 1.0f / (aspect * tan((PI / 360.0f) * fov));
	perspective.mas[5] = 1.0f / tan((PI / 360.0f) * fov);
	perspective.mas[10] = (zFar + zNear) / (zFar - zNear);
	perspective.mas[11] = (-2 * zFar * zNear) / (zFar - zNear);
	perspective.mas[14] = 1.0f;

	return perspective;
}

Matrix4x4f CameraComponent::MakeV()
{
	Matrix4x4f view;
	return view;
}

void CameraComponent::Update()
{

}