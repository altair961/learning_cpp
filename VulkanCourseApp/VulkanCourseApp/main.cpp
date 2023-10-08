#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <iostream>

GLFWwindow* window;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	// Initialize GLFW
	glfwInit();

	// Set GLFW to NOT with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);
}

int main() 
{
	// Create Window
	initWindow("Model viewer", 800, 600);

	// Loop until close
	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
	}

	return 0;
}