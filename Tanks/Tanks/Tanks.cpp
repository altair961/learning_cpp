#include "di.hpp"
#include <iostream>

namespace di = boost::di;

class ILaunch {
public:
	virtual ~ILaunch() noexcept = default;
	virtual void Launch() = 0;
};

class Game : public ILaunch {
public:
	Game(std::string title) {}
	void Launch() override 
	{
		if (true)
		{
			std::cout << "Game Launched!" << std::endl;
		}
	}
};

int main()
{
	auto injector = di::make_injector(
		di::bind<ILaunch>().to<Game>()
	);

	auto game = injector.create<Game>();
	game.Launch();
}

