#include "Scene.h"
#include "Object.h"
#include "CameraComponent.h"
#include "Physics/TransformComponent.h"
#include "Scripts/ScriptComponent.h"

Scene* Scene::instance = nullptr;

Scene::Scene()
{
	
}

Scene::~Scene()
{
	
}

Scene* Scene::getInstance()
{
	if (instance == nullptr) {
		instance = new Scene;

		Object* camera = new Object("camera");
		camera->AddComponent<CameraComponent>("camera");
		instance->objects[camera->GetName()] = camera;
		camera->GetComponent<TransformComponent>("transform")->SetPosition(Vector3f(0.0f, 0.0f, -1.0f));
	}

	return instance;
}

void Scene::delInstance()
{
	if (instance != nullptr) {

		for (auto i = instance->objects.begin(); i != instance->objects.end(); ++i) {
			delete (*i).second;
		}

		delete instance;
		instance = nullptr;
	}
}

int Scene::AddObject(Object* obj)
{
	if (objects.find(obj->GetName()) != objects.end()) {
		return -1;
	}
	instant_objects.push(obj);
	return 0;
}

int Scene::DelObject(Object* obj)
{
	if (objects.find(obj->GetName()) == objects.end()) {
		return -1;
	}
	delete_objects.push(obj);
	return 0;
}

void Scene::Update()
{
	Instantiate();
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		(*i).second->Update();
	}
	Delete();
}

void Scene::SetCamera(int height, int width)
{
	objects["camera"]->GetComponent<CameraComponent>("camera")->SetSize(width, height);
}

Object* Scene::GetCamera()
{
	return objects["camera"];
}

void Scene::Start()
{
	for (auto i = objects.begin(); i != objects.end(); ++i) {
		(*i).second->Start();
	}
}

void Scene::Instantiate()
{
	while(instant_objects.size() > 0) {
		objects[instant_objects.front()->GetName()] = instant_objects.front();
		instant_objects.front()->Start();
		instant_objects.pop();
	}
}

void Scene::Delete()
{
	while (delete_objects.size() > 0) {
		objects.erase(delete_objects.front()->GetName());
		delete delete_objects.front();
		delete_objects.pop();
	}
}