#include "ScriptComponent.h"

ScriptComponent::ScriptComponent(std::unordered_map<std::string, Component*>* components)
	:Component(components)
{
	comp_name = "script";
	script = nullptr;
}

ScriptComponent::~ScriptComponent()
{

}

void ScriptComponent::Start()
{
	script->Start();
}

void ScriptComponent::Update()
{
	script->Update();
}