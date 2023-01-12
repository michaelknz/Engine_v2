#include "MainLoop.h"
#include "Scene.h"

MainLoop::MainLoop(int width, int height, const std::string& title)
	:window(width, height, title)
{
	scene = Scene::getInstance();
	scene->SetCamera(height, width);
}

MainLoop::~MainLoop()
{
	Scene::delInstance();
}

void MainLoop::Loop()
{
	while (window.is_window_ok()) {
		window.ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);
		scene->Update();
		window.SwapWindow();
		window.GetEvents();
	}
}

void MainLoop::Start()
{
	scene->Start();
}