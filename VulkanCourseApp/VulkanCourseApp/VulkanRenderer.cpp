#include "VulkanRenderer.h"

VulkanRenderer::VulkanRenderer()
{
}

VulkanRenderer::~VulkanRenderer()
{
}

int VulkanRenderer::init(GLFWwindow* newWindow) 
{
	window = newWindow;

	try {
		createInstance();
	}
	catch(const std::runtime_error e) {
		printf("ERROR: %s\n", e.what());
		return EXIT_FAILURE;
	}

	return 0;
}

void VulkanRenderer::createInstance()
{
	// Information about application itself. Not just Vulkan, but the whole app we are making here.
	// Most data here doesn't affect the program and is for developer convenience
	// It is for debugging because a lot of error outputs will be repeated here
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Model viewer";			// Custom name of the application
	appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);		// Custom version of the application
	appInfo.pEngineName = "No Engine";					// Custom engine name 
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);	// Custom engine version 
	appInfo.apiVersion = VK_API_VERSION_1_0;			// The Vulkan Version

	// Creation information for a VkInstance (Vulkan instance)
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	// Create list to hold list of extensions
	std::vector<const char*> instanceExtensions = std::vector<const char*>();

	// Set up extensions will use
	uint32_t glfwExtensionCount = 0;	// GLFW may require multiple extensions
	const char** glfwExtensions;		// Extensions passed as array of cstrings, so need pointer (the array) to pointer (cstring)

	// Get GLFW extensions
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount); // this function returns two values: "glfwExtensionCount" and "glfwExtensions"

	// Add GLFW extensions to list of extensions
	for (size_t i = 0; i < glfwExtensionCount; i++)
	{
		instanceExtensions.push_back(glfwExtensions[i]);
	}

	createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
	createInfo.ppEnabledExtensionNames = instanceExtensions.data();

	// TODO: Set up Validation Layers that instance will use
	createInfo.enabledLayerCount = 0;
	createInfo.ppEnabledLayerNames = nullptr;

	// Create instance
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create Vulkan Instance!");
	}
}