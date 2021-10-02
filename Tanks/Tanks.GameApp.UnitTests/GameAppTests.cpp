#include "gtest/gtest.h"
#include "di.hpp"
#include "TanksGameAppImplementations.h"
#include "TanksGameAppInterfaces.h"

TEST(GroupName, When) {

    namespace di = boost::di;

    auto injector = di::make_injector(
        di::bind<IAdd>().to<Adder>()
    );
    Adder adder = injector.create<Adder>();

    int sum = adder.Add(5, 9);

    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}