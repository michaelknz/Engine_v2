#include "BehaviorScript.h"
#include "ScriptComponent.h"

BehaviorScript::BehaviorScript()
{

}

BehaviorScript::~BehaviorScript()
{

}

void BehaviorScript::SetOwner(ScriptComponent* owner)
{
	this->owner = owner;
	transform = owner->GetComponent<TransformComponent>("transform");
}

void BehaviorScript::Start()
{

}

void BehaviorScript::Update()
{

}