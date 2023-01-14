#pragma once
#include <unordered_map>
#include <string>

class Object;

class Prefab {
public:
	Prefab();
	~Prefab();
	static Prefab* getInstance();
	static void delInstance();
	int AddObject(Object* obj, const std::string& name);
	Object* GetObject(const std::string& name);
private:
	static Prefab* instance;
	std::unordered_map<std::string, Object*> prefabs;
};