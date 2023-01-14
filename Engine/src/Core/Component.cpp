#include "Component.h"
#include "Object.h"

Component::Component(Object* obj)
	:object(obj)
{
	comp_name = "default";
}

Component::~Component()
{

}

std::string Component::GetCompName()
{
	return comp_name;
}

void Component::Start()
{

}