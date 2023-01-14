#pragma once
#include <unordered_map>
#include <string>
#include <queue>

class Object;

class Scene {
public:
	Scene();
	~Scene();
	void Update();
	void Start();
	static Scene* getInstance();
	static void delInstance();
	int AddObject(Object* obj);
	int DelObject(Object* obj);
	void Instantiate();
	void Delete();
	void SetCamera(int height, int width);
	Object* GetCamera();
private:
	std::unordered_map<std::string, Object*> objects;
	static Scene* instance;
	std::queue<Object*> instant_objects;
	std::queue<Object*> delete_objects;
};