#include "Object.h"
#include "TransformComponent.h"
#include "Scene.h"

Object::Object(const std::string& name)
	:obj_name(name)
{
	AddComponent<TransformComponent>("transform");
	scene = Scene::getInstance();
}

Object::~Object()
{
	for (auto i = components.begin(); i != components.end(); ++i) {
		delete (*i).second;
	}
}

void Object::Update()
{
	for (auto i = components.begin(); i != components.end(); ++i) {
		(*i).second->Update();
	}
}

void Object::AddToScene()
{
	scene->AddObject(this, obj_name);
}