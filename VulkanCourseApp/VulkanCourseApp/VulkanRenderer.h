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
	void cleanup();

	~VulkanRenderer();

private:
	GLFWwindow* window;

	// Vulkan Components
	VkInstance instance;
	struct {
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;

	// Vulkan functions
	// - Create Functions
	void createInstance();

	// - Get Functions
	void getPhysicalDevice();

	// - Support Functions (they check what extensions are supported etc)
	bool checkInstanceExtensionsSupport(std::vector<const char*> * checkExtensions);
	bool checkDeviceSuitable(VkPhysicalDevice device);
};