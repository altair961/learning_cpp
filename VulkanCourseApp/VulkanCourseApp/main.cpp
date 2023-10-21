#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication
{
public:
    void run()
    {   
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    GLFWwindow* window;
    VkInstance instance;
    void initWindow() 
    {
        std::cout << "at initWindow()" << std::endl;

        glfwInit();
        
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    }

    void initVulkan()
    {
        std::cout << "at initVulkan()" << std::endl;

        createInstance();
    }
    
    void createInstance() 
    {
        std::cout << "at createInstance()" << std::endl;

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
        std::cout << "available extensions:" << std::endl;
        
        for (const auto& extension : extensions)
            std::cout << '\t' << extension.extensionName << '\n';

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0); 
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0); 
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;

        if (!requiredExtensionsPresented(extensions, glfwExtensions))
            throw std::runtime_error("Required extensions not found!");

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
            throw std::runtime_error("failed to create instance!");
    }

    bool requiredExtensionsPresented(
        std::vector<VkExtensionProperties>& availableExtensions, 
        const char** ppRequiredExtArr)
    {
        int requiredExtArrLength = sizeof(ppRequiredExtArr) / sizeof(ppRequiredExtArr[0]);
        std::vector<std::string> availableRequiredMatches;
        for (int i = 0; i < requiredExtArrLength; i++)
        {
            for(VkExtensionProperties availableExtension : availableExtensions)
            {
                std::string requiredExtName = static_cast<std::string>(ppRequiredExtArr[i]);
                if (requiredExtName == availableExtension.extensionName)
                    availableRequiredMatches.push_back(requiredExtName);
            }
 
            if (availableRequiredMatches.size() == 0) 
                break;
        }

        if (availableRequiredMatches.size() != requiredExtArrLength) 
            return false;

        return true;
    }

    void mainLoop() 
    {
        std::cout << "at mainLoop()" << std::endl;

        while (!glfwWindowShouldClose(window)) 
        {
            glfwPollEvents();
        }
    }

    void cleanup()
    {
        std::cout << "at cleanup()" << std::endl;
        vkDestroyInstance(instance, nullptr);
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}