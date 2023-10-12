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
		getPhysicalDevice();
	}
	catch(const std::runtime_error e) {
		printf("ERROR: %s\n", e.what());
		return EXIT_FAILURE;
	}

	return 0;
}

void VulkanRenderer::cleanup()
{
	vkDestroyInstance(instance, nullptr);
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

	// Check Instance extensions supported ...
	if (!checkInstanceExtensionsSupport(&instanceExtensions)) 
	{
		throw std::runtime_error("VkInstance does not support required extensions!");
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

void VulkanRenderer::getPhysicalDevice()
{
	// Enumerate physical devices the vkInstance can access
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);	// here we get deviceCount
	
	// If no devices available, then non support Vulkan!
	if (deviceCount == 0)
	{
		throw std::runtime_error("Can't find GPUs that support Vulkan Instance!");
	}

	// Get list of Physical Devices
	std::vector<VkPhysicalDevice> deviceList(deviceCount);			// here we defined an empty vector of the correct size
	vkEnumeratePhysicalDevices(instance, &deviceCount, deviceList.data());	// here we get deviceCount

	// TEMP: Just pick first device
	mainDevice.physicalDevice = deviceList[0];
}

bool VulkanRenderer::checkInstanceExtensionsSupport(std::vector<const char*>* checkExtensions)
{
	// Need to get number of extensions to create array of correct size to hold extensions
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	// Create an empty list of VkExtensionProperties of correct size
	std::vector<VkExtensionProperties> extensions(extensionCount);
	
	// Populate "extensions" list
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data()); // we are not required to to pass in extensionCount here

	// Check if given extensions are in list of available extensions
	for (const auto& checkExtension : *checkExtensions)
	{
		bool hasExtension = false;
		for (const auto &extension : extensions)
		{
			if (strcmp(checkExtension, extension.extensionName)) 
			{
				hasExtension = true;
				break;
			}
		}

		if (!hasExtension) 
		{
			return false;
		}
	}

	return true;
}

bool VulkanRenderer::checkDeviceSuitable(VkPhysicalDevice device)
{
	/*
	// Information about the device itself (ID, name, type, vendor, etc)
	VkPhysicalDeviceProperties deviceProperties;
	vkGetPhysicalDeviceProperties(device, &deviceProperties);

	// Information about what the device can do (geo shader, tess shader, wide lines, etc)
	VkPhysicalDeviceFeatures deviceFeatures;
	vkGetPhysicalDeviceFeatures(device, &deviceFeatures);
	*/

	return true;
}
