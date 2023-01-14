#include "Object.h"
#include "Physics/TransformComponent.h"
#include "Scene.h"
#include "Prefab.h"

Object::Object(const std::string& name)
	:obj_name(name)
{
	AddComponent<TransformComponent>("transform");
	scene = Scene::getInstance();
}

Object::Object()
	:obj_name("object")
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

Object* Object::Copy()
{
	Object* output = new Object;
	delete output->components["transform"];
	output->components.erase("transform");
	output->obj_name = obj_name;
	output->scene = scene;
	for (auto i = components.begin(); i != components.end(); ++i) {
		Component* new_comp = (*i).second->Copy(output);
		output->components[(*i).first] = new_comp;
	}
	return output;
}

void Object::Update()
{
	for (auto i = components.begin(); i != components.end(); ++i) {
		(*i).second->Update();
	}
}

void Object::Start()
{
	for (auto i = components.begin(); i != components.end(); ++i) {
		(*i).second->Start();
	}
}

void Object::AddToScene()
{
	int i = 1;
	std::string old_name = obj_name;
	std::string tmp_name = obj_name;
	while (scene->AddObject(this) == -1) {
		tmp_name = old_name + "_" + std::to_string(i);
		i++;
		obj_name = tmp_name;
	}
}

void Object::AddToPrefab()
{
	Prefab* pref = Prefab::getInstance();

	int i = 1;
	std::string tmp_name = obj_name;
	while (pref->AddObject(this, tmp_name) == -1) {
		tmp_name = obj_name + "_" + std::to_string(i);
		i++;
	}
	obj_name = tmp_name;
}

std::string Object::GetName()
{
	return obj_name;
}