#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication
{
public:
    void run()
    {
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    void initVulkan()
    {
        std::cout << "at initVulkan()" << std::endl;
    }
    void mainLoop() 
    {
        std::cout << "at mainLoop()" << std::endl;
    }
    void cleanup()
    {
        std::cout << "at cleanup()" << std::endl;
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

