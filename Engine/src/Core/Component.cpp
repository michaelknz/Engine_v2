#include "Component.h"

Component::Component(std::unordered_map<std::string, Component*>* components)
{
	this->components = components;
}

Component::~Component()
{

}