#define OLC_PGE_APPLICATION

#include <iostream>
#include "CustomizedPixelGameEngine.h"
#include "di.hpp"

int main()
{
    namespace di = boost::di;

    auto injector = di::make_injector();
	std::shared_ptr<CustomizedPixelGameEngine> demo = injector.create<std::shared_ptr<CustomizedPixelGameEngine>>();
	

	if (demo->Construct(256, 240, 4, 4))
		demo->Start();


		for (int x = 0; x < demo->ScreenWidth(); x++)
			for (int y = 0; y < demo->ScreenHeight(); y++)
				demo->Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));

	
	return 0;
}