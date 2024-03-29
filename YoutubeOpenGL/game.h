#pragma once
#include "game_state.h"

class Game
{
public:
    // game state
    GameState State;

    bool Keys[1024];

    unsigned int Width, Height;

    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (load all shaders/textures/levels)
    void Init();

    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};