#pragma once
#include "ILaunch.h"

namespace TanksGameInterfaces
{
	class IGame : ILaunch {
	public:
		virtual ~IGame() noexcept = default;
	};
}