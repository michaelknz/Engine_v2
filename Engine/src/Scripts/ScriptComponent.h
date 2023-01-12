#pragma once
#include "Core/Component.h"
#include "BehaviorScript.h"

class ScriptComponent :public Component {
public:
	ScriptComponent(std::unordered_map<std::string, Component*>* components);
	~ScriptComponent() override;
	virtual void Update() override;
	virtual void Start();
	friend void BehaviorScript::SetOwner(ScriptComponent*);
	template<typename T>
	void SetScript()
	{
		script = new T;
		script->SetOwner(this);
	}
private:
	BehaviorScript* script;
};