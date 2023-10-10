#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

class VulkanRenderer 
{
public:
	VulkanRenderer();

	int init(GLFWwindow* newWindow);

	~VulkanRenderer();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;

	// Vulkan functions
	// - Create Functions
	void createInstance();

	// - Support Functions
	bool checkInstanceExtensionsSupport(std::vector<const char*> * checkExtensions);
};