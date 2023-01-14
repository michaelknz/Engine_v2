#pragma once
#include "Core/Component.h"
#include "BehaviorScript.h"
#include <functional>

class Object;

template<typename T>
static void set_script(ScriptComponent* scr)
{
	scr->script = new T;
	scr->script->SetOwner(scr);
}

class ScriptComponent :public Component {
public:
	ScriptComponent(Object* obj);
	~ScriptComponent() override;
	virtual void Update() override;
	virtual void Start() override;
	friend void BehaviorScript::SetOwner(ScriptComponent*);
	template<typename T>
	friend void set_script(ScriptComponent*);
	Component* Copy(Object* obj) override;
	template<typename T>
	void SetScript()
	{
		set_script<T>(this);
		create_f = &set_script<T>;
	}
private:
	BehaviorScript* script;
	std::function<void(ScriptComponent*)> create_f;
};