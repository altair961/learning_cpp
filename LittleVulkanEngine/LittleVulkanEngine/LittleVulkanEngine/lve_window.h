#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace lve { // lve means little vulkan engine
	class LiveWindow {
	public:
		LiveWindow(int w, int h, std::string name);
		~LiveWindow();

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}