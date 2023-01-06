#pragma once
#include <unordered_map>
#include <string>

class Object;

class Scene {
public:
	Scene();
	~Scene();
	void Update();
	static Scene* getInstance();
	static void delInstance();
	void AddObject(Object* obj, std::string name);
private:
	std::unordered_map<std::string, Object*> objects;
	static Scene* instance;
};