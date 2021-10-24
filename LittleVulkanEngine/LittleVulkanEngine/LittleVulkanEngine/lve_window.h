#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace lve { // lve means little vulkan engine
	class LveWindow {
	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		// We delete copy constructor and copy operator. This is because we are using a pointer to our glfw window
		// We adhere to RAII principle. RAII means, that resource creation happens when we initialize our variable and 
		// their cleanups are performed by their distructors
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}