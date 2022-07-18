#include "Game.h"
#include <memory>
#include "RenderEngine.h"

int main()
{
    std::shared_ptr<RenderEngine> pRenderEng;
    pRenderEng.reset();
    pRenderEng = std::make_shared<RenderEngine>("Tanks game");
    Game game = Game(pRenderEng);
    game.Launch();

    return 0;
}