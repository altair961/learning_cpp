#include "pch.h"
#include "di.hpp"

#include "TanksGameAppImplementations.h"
#include "TanksGameAppInterfaces.h"


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

TEST(TestCaseName1, TestName2) {

    namespace di = boost::di;

    auto injector = di::make_injector(
        di::bind<IAdd>().to<Adder>()
    );
    Adder adder = injector.create<Adder>();

    int sum = adder.Add(5, 9);
    
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

//int main()
//{
//	std::cout << "Hello World!\n";
//}