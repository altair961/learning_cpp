#pragma once
class IGraphicsEngine {
public:
	std::shared_ptr<olc::PixelGameEngine> GraphicsEngineInstance;
	virtual void ConstructEngine(int scrWidth, int scrHeight, int pxWidth, int pxHeight) = 0;
	virtual void StartEngine() = 0;
};