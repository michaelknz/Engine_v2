#include "Window.h"

Window::Window(int width, int height, const std::string& title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	
}

Window::~Window()
{
	glfwTerminate();
}

void Window::SwapWindow()
{
	glfwSwapBuffers(window);
}

void Window::GetEvents()
{
	glfwPollEvents();
}

void Window::ClearWindow(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::is_window_ok()
{
	return !glfwWindowShouldClose(window);
}