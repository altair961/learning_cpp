#define CATCH_CONFIG_MAIN
#include <map>
#include <cstdint>

#include "./catch.hpp"

struct Portal {
	enum class Type { Snake, Ladder };
	Type type;
	uint32_t target;
};
struct Action {
	enum class Type { Move, Win };
	Type type;
	uint32_t target;

	bool operator==(const Action& rhs) const {
		return std::tie(type, target) == std::tie(rhs.type, rhs.target);
	}
};

CATCH_REGISTER_ENUM(Action::Type, Action::Type::Move, Action::Type::Win);
class Board {
	static const int size = 100;
	static const std::map<uint32_t, Portal> portals;

public:
	Action landOn(uint32_t square) const {
		auto finalSquare = [square] {
			auto it = portals.find(square);
			if (it != portals.end())
				return square;
		}();

		if(finalSquare == size)
			return { Action::Type::Win, size };
		else
			return { Action::Type::Move, finalSquare };
	}
};

TEST_CASE("Board can tell us what action to perform")
{
	Board board;
	REQUIRE(board.landOn(1) == Action{ Action::Type::Move, 1 });
	REQUIRE(board.landOn(3).target == 3);
	REQUIRE(board.landOn(2).target == 38);
	REQUIRE(board.landOn(47).target == 26);
	REQUIRE(board.landOn(100).type == Action::Type::Win);
	REQUIRE(board.landOn(80).type == Action::Type::Win);
}

const std::map<uint32_t, Portal> Board::portals =
{
	{ 2, { Portal::Type::Ladder, 38 } },
	{ 4, { Portal::Type::Ladder, 14 } },
	{ 8, { Portal::Type::Ladder, 31 } },
	{ 21, { Portal::Type::Ladder, 42 } },
	{ 28, { Portal::Type::Ladder, 84 } },
	{ 36, { Portal::Type::Ladder, 44 } },
	{ 47, { Portal::Type::Snake, 26 } },
	{ 49, { Portal::Type::Snake, 11 } },
	{ 51, { Portal::Type::Ladder, 67 } },
	{ 56, { Portal::Type::Snake, 53 } },
	{ 62, { Portal::Type::Snake, 18 } },
	{ 64, { Portal::Type::Snake, 60 } },
	{ 71, { Portal::Type::Ladder, 91 } },
	{ 80, { Portal::Type::Ladder, 100 } },
	{ 87, { Portal::Type::Snake, 24 } },
	{ 93, { Portal::Type::Snake, 73 } },
	{ 95, { Portal::Type::Snake, 75 } },
	{ 98, { Portal::Type::Snake, 78 } },
};