#include "di.hpp"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


namespace di = boost::di;

class ILaunch {
public:
	virtual ~ILaunch() noexcept = default;
	virtual void Launch(std::string name) = 0;
};

class Game : public ILaunch {
public:
	Game(std::string title) {}
	void Launch(std::string name) override 
	{

		if (name == "")
		{
			throw new std::invalid_argument("name string parameter is empty");
		}
	}
};
//
//int main()
//{
//	auto injector = di::make_injector(
//		di::bind<ILaunch>().to<Game>()
//	);
//
//	auto game = injector.create<Game>();
//	game.Launch();
//}

TEST_CASE("When Game is launched with empty string should throw invalid_argument exception", "[factorial]") {
	auto injector = di::make_injector(
	di::bind<ILaunch>().to<Game>());

	auto game = injector.create<Game>();

	REQUIRE_THROWS_AS(game.Launch(""), std::invalid_argument);
}