#pragma once
#include <unordered_map>
#include <string>
#include "Object.h"

class Component {
public:
	Component(Object* obj);
	virtual ~Component();
	virtual void Update() = 0;
	virtual void Start();
	std::string GetCompName();
	virtual Component* Copy(Object* obj) = 0;
protected:
	template<typename T>
	T* GetComponent(const std::string& name)
	{
		return object->GetComponent<T>(name);
	}
	
	template<typename T>
	std::vector<T*> GetComponent()
	{
		return object->GetComponent<T>();
	}
	std::string comp_name;
	Object* object;
};