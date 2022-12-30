#include "MainLoop.h"

MainLoop::MainLoop(int width, int height, const std::string& title)
	:window(width, height, title)
{

}

MainLoop::~MainLoop()
{

}

void MainLoop::Loop()
{
	while (window.is_window_ok()) {
		window.ClearWindow(0.5f, 0.5f, 0.5f, 1.0f);

		window.SwapWindow();
		window.GetEvents();
	}
}