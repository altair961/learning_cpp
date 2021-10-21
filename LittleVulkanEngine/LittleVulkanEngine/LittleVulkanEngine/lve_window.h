#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace lve { // lve means little vulkan engine
	class LiveWindow {
	public:
		LiveWindow(int w, int h, std::string name);
		~LiveWindow();

		// We delete copy constructor and copy operator. This is because we are using a pointer to our glfw window
		// We adhere to RAII principle. RAII means, that resource creation happens when we initialize our variable and 
		// their cleanups are performed by their distructors
		LiveWindow(const LiveWindow&) = delete;
		LiveWindow& operator=(const LiveWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}