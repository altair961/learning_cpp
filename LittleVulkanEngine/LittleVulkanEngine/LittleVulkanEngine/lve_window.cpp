#include "lve_window.h"

namespace lve {
	LiveWindow::LiveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	LiveWindow::~LiveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LiveWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}