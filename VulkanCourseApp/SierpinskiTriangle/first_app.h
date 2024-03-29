#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"
#include "lve_device.h"
#include "lve_swap_chain.h"
#include "lve_model.h"

// std
#include <memory>
#include <vector>

namespace lve {
	class FirstApp {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;


		void run();

	private:
		void getSierpinskiTriangle(std::vector<LveModel::Vertex> &vertices);
		void convertToCartesianCoordinates(std::vector<lve::LveModel::Vertex>& vertices);
		void convertToVulkanCoordinates(std::vector<lve::LveModel::Vertex>& vertices);
		void flipYCoordinate(std::vector<lve::LveModel::Vertex>& vertices);
		void getNextLevelTriangle(int recursionStep, 
			std::vector<LveModel::Vertex>& vertices);
		void loadModels();
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		LveWindow lveWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LveDevice lveDevice{ lveWindow };
		LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() };
		std::unique_ptr<LvePipeline> lvePipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		std::unique_ptr<LveModel> lveModel;
	};
}
