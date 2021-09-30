#include "pch.h"
#include "di.hpp"

class IView {
public:
    virtual ~IView() noexcept = default;
    virtual void update() = 0;
};

class View : public IView {
public:
    int screenWidthPx = 900;
    View(std::string title) {}
    void update() override { }
};

TEST(TestCaseName, TestName) {

    namespace di = boost::di;

    auto injector = di::make_injector(
        di::bind<IView>().to<View>()
    );
    auto view = injector.create<View>();

    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


//int main()
//{
//	std::cout << "Hello World!\n";
//}