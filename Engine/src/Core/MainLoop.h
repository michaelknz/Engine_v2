#pragma once
#include "Window.h"

class MainLoop {
public:
	MainLoop(int width, int height, const std::string& title);
	~MainLoop();
	void Loop();
private:
	Window window;
};