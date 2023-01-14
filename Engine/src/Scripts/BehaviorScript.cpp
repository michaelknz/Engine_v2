#include "BehaviorScript.h"
#include "ScriptComponent.h"
#include "Core/Object.h"
#include "Core/Scene.h"

BehaviorScript::BehaviorScript()
{

}

BehaviorScript::~BehaviorScript()
{

}

void BehaviorScript::SetOwner(ScriptComponent* owner)
{
	transform = owner->GetComponent<TransformComponent>("transform");
	parent_object = owner->object;
}

void BehaviorScript::DestroyObject(Object* obj)
{
	Scene* scene = Scene::getInstance();
	scene->DelObject(obj);
}

Object* BehaviorScript::Instantiate(Object* obj)
{
	Object* sc_obj = obj->Copy();
	Scene* scene = Scene::getInstance();
	sc_obj->AddToScene();
	return sc_obj;
}

void BehaviorScript::Start()
{

}

void BehaviorScript::Update()
{

}