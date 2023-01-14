#pragma once
#include "Scripts/BehaviorScript.h"
#include "Core/Prefab.h"

class QuadScript :public BehaviorScript {
public:
	void Start() override
	{
		angle = 0.0f;
		y = 0;
		Instantiate(Prefab::getInstance()->GetObject("sm"));
	}
	void Update() override {
		angle += 1.0f;
		if (angle >= 360.0f) {
			angle -= 360.0f;
		}
		y++;
		if (y == 100) {
			Instantiate(Prefab::getInstance()->GetObject("sm"));
			y = 0;
		}
		transform->SetRotation(Vector3f(0, 0, angle));
	}
private:
	float angle;
	int y;
};