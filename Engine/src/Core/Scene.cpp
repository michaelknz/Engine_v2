#include "Scene.h"
#include "Object.h"

Scene* Scene::instance = nullptr;

Scene::Scene()
{

}

Scene::~Scene()
{
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		delete (*i).second;
	}
}

Scene* Scene::getInstance()
{
	if (instance == nullptr) {
		instance = new Scene;
	}
	return instance;
}

void Scene::delInstance()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void Scene::AddObject(Object* obj, std::string name)
{
	objects[name] = obj;
}

void Scene::Update()
{
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		(*i).second->Update();
	}
}