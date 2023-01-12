#pragma once
#include "Scripts/BehaviorScript.h"

class QuadScript :public BehaviorScript {
public:
	void Start() override;
	void Update() override;
private:
	float angle;
};