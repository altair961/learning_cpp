#include "first_app.h"

// std
#include <stdexcept>
#include <array>
#include <iostream>

namespace lve {

	FirstApp::FirstApp() {
		loadModels();
		createPipelineLayout();
		createPipeline();
		createCommandBuffers();
	}

	FirstApp::~FirstApp() {
		vkDestroyPipelineLayout(lveDevice.device(), pipelineLayout, nullptr);
	}

	void FirstApp::run() {
		while (!lveWindow.shouldClose()) {
			glfwPollEvents();
			drawFrame();
		}

		vkDeviceWaitIdle(lveDevice.device());
	}

	void FirstApp::loadModels() {
		std::vector<LveModel::Vertex> vertices{};
		getSierpinskiTriangle(vertices);
		lveModel = std::make_unique<LveModel>(lveDevice, vertices);
	}

	void FirstApp::createPipelineLayout() {
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		
		if (vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo,
			nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout");
		}
	}

	void FirstApp::createPipeline() {
		auto pipelineConfig = LvePipeline::defaultPipelineConfig(
			lveSwapChain.width(), lveSwapChain.height());
		pipelineConfig.renderPass = lveSwapChain.getRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		lvePipeline = std::make_unique<LvePipeline>(
			lveDevice,
			"shaders\\vert.spv",
			"shaders\\frag.spv",
			pipelineConfig
		);
	}

	void FirstApp::createCommandBuffers() {
		commandBuffers.resize(lveSwapChain.imageCount());
		
		VkCommandBufferAllocateInfo allocInfo{};

		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = lveDevice.getCommandPool();
		allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

		if (vkAllocateCommandBuffers(lveDevice.device(), &allocInfo, commandBuffers.data()) !=
			VK_SUCCESS) {
			throw std::runtime_error("failed to allocate command buffers!");
		}

		for (int i = 0; i < commandBuffers.size(); i++) {
			VkCommandBufferBeginInfo beginInfo{};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

			if (vkBeginCommandBuffer(commandBuffers[i], &beginInfo) !=
				VK_SUCCESS)
			{
				throw std::runtime_error("failed to begin recording command buffer!");
			}

			VkRenderPassBeginInfo renderPassInfo{};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = lveSwapChain.getRenderPass();
			renderPassInfo.framebuffer = lveSwapChain.getFrameBuffer(i);

			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = lveSwapChain.getSwapChainExtent();

			std::array<VkClearValue, 2> clearValues{};
			clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f};
			clearValues[1].depthStencil = {1.0f, 0};
			renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
			renderPassInfo.pClearValues = clearValues.data();

			vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
			
			lvePipeline->bind(commandBuffers[i]);
			lveModel->bind(commandBuffers[i]);
			lveModel->draw(commandBuffers[i]);
			
			vkCmdEndRenderPass(commandBuffers[i]);
			if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS) {
				throw std::runtime_error("failed to record command buffer!");
			}
		}
	}

	void FirstApp::drawFrame() {
		uint32_t imageIndex;
		auto result = lveSwapChain.acquireNextImage(&imageIndex);
		if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
			throw std::runtime_error("failed to acquire swap chain image!");
		}

		result = lveSwapChain.submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("failed to present swap chain image!");
		}
	}

	void FirstApp::getSierpinskiTriangle(std::vector<LveModel::Vertex> &vertices) {
		vertices.push_back({ {0.0f, -0.5f} }); // top-center
		vertices.push_back({ {0.5f, 0.5f} }); // bottom-right
		vertices.push_back({ {-0.5f, 0.5f} }); // bottom-right
		
		//vertices.clear();
		//vertices.push_back({ {0.0f, 0.0f} }); // top-center
		//vertices.push_back({ {0.0f, 0.0f} }); // bottom-right
		//vertices.push_back({ {0.0f, 0.0f} }); // bottom-right



	/*	vertices.push_back({ {1.0f, -1.5f} });
		vertices.push_back({ {1.5f, 1.5f} });
		vertices.push_back({ {-0.5f, 0.5f} });*/


		convertToCartesianCoordinates(vertices);

		//std::vector<LveModel::Vertex> vertices{ {{0.0f, -0.5f}},	{{0.5f, 0.5f}},
		//	{{-0.5f, 0.5f}}
		//};
		
		getNextLevelTriangle(7, vertices);
		std::cout << "exited recursion ";

		convertToVulkanCoordinates(vertices);
	}

	void FirstApp::getNextLevelTriangle(int recursionStep,
		std::vector<LveModel::Vertex>& vertices) {
		if (recursionStep == 0 || recursionStep < 0)
			return;

		auto& v0 = vertices.at(0); // top-center
		auto& v1 = vertices.at(1); // bottom-right
		auto& v2 = vertices.at(2); // bottom-left
		//v2.position.x += 0.7f;


		auto m0X = (v0.position.x + v1.position.x) / 2;
		auto m0Y = (v0.position.y + v1.position.y) / 2;
		LveModel::Vertex m0 = { {m0X, m0Y} };

		auto m1X = (v1.position.x + v2.position.x) / 2;
		auto m1Y = (v1.position.y + v2.position.y) / 2;
		LveModel::Vertex m1 = { {m1X, m1Y} };

		auto m2X = (v2.position.x + v0.position.x) / 2;
		auto m2Y = (v2.position.y + v0.position.y) / 2;
		LveModel::Vertex m2 = { {m2X, m2Y} };



		//vertices.at(0) = { {m0X, m0Y} };

		vertices.clear();
		LveModel::Vertex t2v1{ {v1.position.x, v1.position.y}};
		LveModel::Vertex t2v2{ {v2.position.x, v2.position.y}};

		vertices.push_back(v0);
		vertices.push_back(m0);
		vertices.push_back(m2);

		vertices.push_back(m0); //0.25 0.0
		vertices.push_back(t2v1);
		vertices.push_back(m1);

		vertices.push_back(m2);
		vertices.push_back(m1);
		vertices.push_back(t2v2);


		//LveModel::Edge edge{};
		//edge.vertices.push_back(v0);
		//edge.vertices.push_back(v1);

		// getEdges
		//for (int i = 0; i < 3; i++)
		//{
		//	auto a = vertices.at(i);
		//	auto b = vertices.at(i + 1);
		//}

//		LveModel::Vertex vert = { {mX, mY } };

		//vertices.at(0) = vert;

		recursionStep--;
		std::cout << "heigh ho step " << recursionStep << '\n';
		getNextLevelTriangle(recursionStep, vertices);
	}

	void FirstApp::convertToCartesianCoordinates(std::vector<lve::LveModel::Vertex>& vertices)
	{
		flipYCoordinate(vertices);
	}

	void FirstApp::convertToVulkanCoordinates(std::vector<lve::LveModel::Vertex>& vertices)
	{
		flipYCoordinate(vertices);
	}
	
	void FirstApp::flipYCoordinate(std::vector<lve::LveModel::Vertex>& vertices) {
		for (auto& vertex : vertices)
			vertex.position.y = vertex.position.y * -1;
	}
}