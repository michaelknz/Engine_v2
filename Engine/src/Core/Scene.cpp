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
		instance->AddObject(camera, "camera");
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
		ScriptComponent* script = (*i).second->GetComponent<ScriptComponent>("script");
		if (script != nullptr) {
			script->Start();
		}
	}
}