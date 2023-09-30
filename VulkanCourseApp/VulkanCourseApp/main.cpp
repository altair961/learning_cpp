#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* window;
void initWindow(std::string wName = "Test Window",
	const int width = 800, const int height = 600)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, false);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main()
{
	// Create window
	initWindow("Test window", 800, 600);

	// Loop until closed
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	// Destroy GLFW window and stop GLFW
	glfwDestroyWindow(window);
	glfwTerminate();
}