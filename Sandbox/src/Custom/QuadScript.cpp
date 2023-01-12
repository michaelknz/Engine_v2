#include "QuadScript.h"

void QuadScript::Start()
{
	angle = 0.0f;
}

void QuadScript::Update()
{
	angle += 1.0f;
	if (angle >= 360.0f) {
		angle -= 360.0f;
	}
	transform->SetRotation(Vector3f(0, 0, angle));
}