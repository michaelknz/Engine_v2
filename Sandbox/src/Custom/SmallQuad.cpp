#pragma once
#include "Scripts/BehaviorScript.h"

class SmallQuad :public BehaviorScript {
public:
	void Start() override
	{
		x = 0;
		y = 0;
		z = 0;
		transform->SetScale(Vector3f(0.25f, 0.25, 1.0f));
	}

	void Update() override
	{
		x += 0.01;
		z += 1.0f;
		transform->SetPosition(Vector3f(0, x, 0));
		transform->SetRotation(Vector3f(0, 0, z));
		y++;
		if (y == 100) {
			DestroyObject(parent_object);
		}
	}
private:
	float x;
	int y;
	float z;
};