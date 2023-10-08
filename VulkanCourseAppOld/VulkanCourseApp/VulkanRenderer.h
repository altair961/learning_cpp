#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>


class VulkanRenderer
{
public:
	VulkanRenderer();
	int init(GLFWwindow* window);
	~VulkanRenderer();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;

	// Vulkan functions
	void createInstance();
};

