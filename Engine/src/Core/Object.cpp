#include "Object.h"
#include "TransformComponent.h"

Object::Object()
{
	AddComponent<TransformComponent>("transform");
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