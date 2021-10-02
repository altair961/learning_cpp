#include "pch.h"
#include "TanksGameAppImplementations.h"
#include "TanksGameAppInterfaces.h"

TEST(GroupName, When_StartInvoked_Should_invoke) {

    namespace di = boost::di;

    auto injector = di::make_injector(
        di::bind<IAdd>().to<Adder>()
    );
    std::shared_ptr<Adder> adder = injector.create<std::shared_ptr<Adder>>();

    int sum = adder->Add(5, 9);

    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}