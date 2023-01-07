#pragma once
#include <Glad/glad.h>
#include <unordered_map>
#include <string>
#include <type_traits>

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
		T* comp = new T(&components);
		components.insert(std::make_pair(name, comp));
		return 0;
	}
	template<typename T>
	T* GetComponent(const std::string& name)
	{
		return static_cast<T*>(components->at(name));
	}
private:
	std::unordered_map<std::string, Component*> components;
	Scene* scene;
	std::string obj_name;
};