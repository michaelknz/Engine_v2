#include "ScriptComponent.h"
#include "BehaviorScript.h"

ScriptComponent::ScriptComponent(Object* obj)
	:Component(obj)
{
	comp_name = "script";
	script = nullptr;
}

ScriptComponent::~ScriptComponent()
{
	if (script != nullptr) {
		delete script;
		script = nullptr;
	}
}

void ScriptComponent::Start()
{
	script->Start();
}

void ScriptComponent::Update()
{
	script->Update();
}

Component* ScriptComponent::Copy(Object* obj)
{
	ScriptComponent* output = new ScriptComponent(object);
	*output = *this;
	output->object = obj;
	output->create_f(output);
	return output;
}