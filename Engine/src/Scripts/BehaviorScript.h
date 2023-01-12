#pragma once
#include "Physics/TransformComponent.h"
#include "Math/MathStructs.h"

class ScriptComponent;
class TransformComponent;

class BehaviorScript {
public:
	BehaviorScript();
	virtual ~BehaviorScript();
	void SetOwner(ScriptComponent* owner);
	virtual void Start();
	virtual void Update();
protected:
	TransformComponent* transform;
private:
	ScriptComponent* owner;
};