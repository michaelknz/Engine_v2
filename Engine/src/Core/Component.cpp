#include "Component.h"

Component::Component(std::unordered_map<std::string, Component*>* components)
{
	this->components = components;
	comp_name = "default";
}

Component::~Component()
{

}

std::string Component::GetCompName()
{
	return comp_name;
}