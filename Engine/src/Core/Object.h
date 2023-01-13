#pragma once
#include <Glad/glad.h>
#include <unordered_map>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <vector>
#include <iostream>

class Component;
class Scene;

class Object {
public:
	Object(const std::string& name);
	virtual ~Object();
	void Update();
	void AddToScene();

	template<typename T>
	bool AddComponent(const std::string& name)
	{
		if (!std::is_base_of_v<Component, T>) {
			return -1;
		}
		if (components.find(name) != components.end()) {
			return -1;
		}
		T* comp = new T(&components);
		components.insert(std::make_pair(name, comp));
		return 0;
	}

	template<typename T>
	bool AddComponent()
	{
		if (!std::is_base_of_v<Component, T>) {
			return -1;
		}
		T* comp = new T(&components);
		if (components.find(comp->GetCompName()) == components.end()) {
			components.insert(std::make_pair(comp->GetCompName(), comp));
			return 0;
		}
		int i = 1;
		while (true) {
			std::string tmp = comp->GetCompName() + "_" + std::to_string(i);
			if (components.find(tmp) == components.end()) {
				components.insert(std::make_pair(tmp, comp));
				return 0;
			}
			i++;
		}
	}

	template<typename T>
	T* GetComponent(const std::string& name)
	{
		if (components.find(name) == components.end()) {
			return nullptr;
		}
		return static_cast<T*>(components.at(name));
	}

	template<typename T>
	std::vector<T*> GetComponent()
	{
		std::vector<T*> output;
		for (auto i = components.begin(); i != components.end(); ++i) {
			if (typeid(*((*i).second)) == typeid(T)) {
				output.push_back(static_cast<T*>((*i).second));
			}
		}
		return output;
	}
private:
	std::unordered_map<std::string, Component*> components;
	Scene* scene;
	std::string obj_name;
};