#include "IView.h"
#include <string>

namespace TanksGameAppImplementations
{
	using namespace TanksGameAppInterfaces;

	class View : public IView {
	public:
		View(std::string title) {}
		void update() override {}
	};
}