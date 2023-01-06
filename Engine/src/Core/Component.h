#pragma once
#include <unordered_map>
#include <string>

class Component {
public:
	Component(std::unordered_map<std::string, Component*>* components);
	virtual ~Component();
	virtual void Update() = 0;
protected:
	template<typename T>
	T GetComponent(const std::string& name)
	{
		return static_cast<T*>(components->at(name));
	}
private:
	std::unordered_map<std::string, Component*>* components;
};