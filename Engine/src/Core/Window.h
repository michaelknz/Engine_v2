#pragma once
#include <Glad/glad.h>
#include <string>
#include <glfw3.h>

class Window {
public:
	Window(int width, int height, const std::string& title);
	~Window();
	void SwapWindow();
	void GetEvents();
	void ClearWindow(float r, float g, float b, float a);
	bool is_window_ok();
private:
	GLFWwindow* window;
};