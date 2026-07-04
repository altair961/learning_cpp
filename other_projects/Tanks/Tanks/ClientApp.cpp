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

    constexpr int width = 256;
    constexpr int height = 240;
    constexpr int pixelSide = 4;
    constexpr bool isFullScrOn = false;
    constexpr bool isVSyncOn = true;

    pe.Initialize(width, height, pixelSide, pixelSide, isFullScrOn, isVSyncOn);
    bool isPeInitialized = pe.GetIsInitialized();

    if (isPeInitialized)
        pe.Launch();
}