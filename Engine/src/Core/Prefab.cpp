#include "Prefab.h"
#include "Object.h"

Prefab* Prefab::instance = nullptr;

Prefab::Prefab()
{

}

Prefab::~Prefab()
{

}

Prefab* Prefab::getInstance()
{
	if (instance == nullptr) {
		instance = new Prefab;
	}
	return instance;
}

void Prefab::delInstance()
{
	if (instance == nullptr) {
		return;
	}
	for (auto i = instance->prefabs.begin(); i != instance->prefabs.end(); ++i) {
		delete (*i).second;
	}
	delete instance;
	instance = nullptr;
}

int Prefab::AddObject(Object* obj, const std::string& name)
{
	if (prefabs.find(name) != prefabs.end()) {
		return -1;
	}
	prefabs[name] = obj;
	return 0;
}

Object* Prefab::GetObject(const std::string& name)
{
	if (prefabs.find(name) == prefabs.end()) {
		return nullptr;
	}
	return prefabs[name];
}