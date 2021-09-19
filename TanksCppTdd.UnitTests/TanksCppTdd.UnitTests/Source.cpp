// $CXX -std=c++14 basic_create_objects_tree.cpp
#include "di.hpp"

namespace di = boost::di;

struct renderer {
	int device;
};

class iview {
public:
	virtual ~iview() noexcept = default;
	virtual void update() = 0;
};

class gui_view : public iview {
public:
	gui_view(std::string title, const renderer&) {}
	void update() override {}
};

class text_view : public iview {
public:
	void update() override {}
};
class model {};

class controller {
private:
	int distanceMeters = 5;
public:
	controller(model&, iview&) {}
};

class user {};

class app {
	controller& controller2;

	//explicit app(const std::shared_ptr<Engine>& engine)
	//	: engine{ engine }
	//{
	//}

public:
	app(controller& _controller, user&) : controller2{ _controller } 
	{
		;
	}
};

int main() {
	/**
	 * renderer renderer_;
	 * view view_{"", renderer_};
	 * model model_;
	 * controller controller_{model_, view_};
	 * user user_;
	 * app app_{controller_, user_};
	 */

	auto injector = di::make_injector(
		di::bind<iview>().to<gui_view>()
		, di::bind<int>().to(42) // renderer device
	);

	injector.create<app>();
}