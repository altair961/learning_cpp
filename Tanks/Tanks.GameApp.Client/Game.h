#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	static SDL_Renderer* renderer;

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
};