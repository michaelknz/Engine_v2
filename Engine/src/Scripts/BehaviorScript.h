#pragma once
#include "Physics/TransformComponent.h"
#include "Math/MathStructs.h"

class ScriptComponent;
class TransformComponent;
class Object;

class BehaviorScript {
public:
	BehaviorScript();
	virtual ~BehaviorScript();
	virtual void Start();
	virtual void Update();
	void SetOwner(ScriptComponent* owner);
protected:
	TransformComponent* transform;
	void DestroyObject(Object* obj);
	Object* Instantiate(Object* obj);
	Object* parent_object;
};