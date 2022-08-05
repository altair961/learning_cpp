#define OLC_PGE_APPLICATION
#include <iostream>
#include "PixelEngine.h"
#include <memory>

int main()
{
    std::shared_ptr<Game> pGame;
    pGame.reset();
    pGame = std::make_shared<Game>();
    PixelEngine pe(pGame);
    pe.Initialize(256, 240, 4, 4, false, true);
    bool isPeInitialized = pe.GetIsInitialized();

    if (isPeInitialized)
        pe.Launch();
}