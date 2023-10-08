#include "VulkanRenderer.h"
#include <vector>

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
	catch(const std::runtime_error &e) {
		printf("ERROR: %s\n", e.what());
		return EXIT_FAILURE;
	}

	return 0;
}

void VulkanRenderer::createInstance()
{
	// Information about the application itself. 
	// Not specifically Vulkan app, but whole app we are making here.
	// Most data here doesn't affect the program and is for developer 
	// convenience. So it doesn't do anything. It is for debugging.
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan app";				// Custom name of the application
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);	// Custom versin of the application
	appInfo.pEngineName = "No Engine";						// Name of the engine that you develop or name of the engine you are usuing
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);		// Custom engine version
	appInfo.apiVersion = VK_API_VERSION_1_0;				// The Vulkan version

	// Creation information for a VkInstance (Vulkan Instance)
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	
	// Create a list to hold instance extensions
	std::vector<const char*> instanceExtensions = std::vector <const char*>();

	// Set up extensions Instance we will use
	uint32_t glfwExtensionCount = 0;	// GLFW may require multiple extensions
	const char** glfwExtensions;		// Extensions passed as array of cstrings, so need pointer (the array) to pointer (the cstring). So it's an array of pointers. 

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	28:15
}