#pragma once
#include <unordered_map>
#include <string>

class Component {
public:
	Component(std::unordered_map<std::string, Component*>* components);
	virtual ~Component();
	virtual void Update() = 0;
	std::string GetCompName();
protected:
	template<typename T>
	T* GetComponent(const std::string& name)
	{
		if (components->find(name) == components->end()) {
			return nullptr;
		}
		return static_cast<T*>(components->at(name));
	}
	
	template<typename T>
	std::vector<T*> GetComponent()
	{
		std::vector<T*> output;
		for (auto i = components->begin(); i != components->end(); ++i) {
			if (typeid(*((*i).second)) == typeid(T)) {
				output.push_back((*i).second);
			}
		}
		return output;
	}
	std::string comp_name;
private:
	std::unordered_map<std::string, Component*>* components;
};