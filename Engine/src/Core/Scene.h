#pragma once
#include <unordered_map>
#include <string>

class Object;

class Scene {
public:
	Scene();
	~Scene();
	void Update();
	void Start();
	static Scene* getInstance();
	static void delInstance();
	void AddObject(Object* obj, std::string name);
	void SetCamera(int height, int width);
	Object* GetCamera();
private:
	std::unordered_map<std::string, Object*> objects;
	static Scene* instance;
};