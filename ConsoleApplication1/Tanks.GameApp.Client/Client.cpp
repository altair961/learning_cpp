#define OLC_PGE_APPLICATION

#include <iostream>
#include "CustomizedPixelGameEngine.h"
#include "HeaderExample.h"
#include "di.hpp"

int main()
{
    namespace di = boost::di;

    auto injector = di::make_injector();
	std::shared_ptr<CustomizedPixelGameEngine> demo = injector.create<std::shared_ptr<CustomizedPixelGameEngine>>();

	if (demo->Construct(256, 240, 4, 4))
		demo->Start();

	return 0;
}