#pragma once
#include "Window.h"

class Scene;

class MainLoop {
public:
	MainLoop(int width, int height, const std::string& title);
	~MainLoop();
	void Loop();
	void Start();
private:
	Window window;
	Scene* scene;
};