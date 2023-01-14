#include "CameraComponent.h"
#include "Physics/TransformComponent.h"
#include "Math/MatrixOperations.h"

CameraComponent::CameraComponent(Object* obj)
	:Component(obj), width(0), height(0)
{
	comp_name = "camera";
	fov = 90.0;
	zNear = 0.1;
	zFar = 100.0;
	transform = GetComponent<TransformComponent>("transform");
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

Component* CameraComponent::Copy(Object* obj)
{
	CameraComponent* output = new CameraComponent(object);
	*output = *this;
	output->object = obj;
	return output;
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
	perspective.mas[15] = 0.0f;

	return perspective;
}

Matrix4x4f CameraComponent::MakeV()
{
	Matrix4x4f view;
	view = MatrixOperations::Translate(-1 * transform->GetPosition());
	view = MatrixOperations::Rotation(-1 * transform->GetRotation()) * view;
	return view;
}

void CameraComponent::Update()
{

}