#include "pch.h"
//#include "MathLibrary.h"
#include "di.hpp"
#include "IView.h"

namespace di = boost::di;

TEST(TestCaseName, WhenLaunchInvoked_ShouldInvoke_GameEngineStart) {
	//using namespace TanksGameApp;
	//using namespace TanksGameAppImpl;

	View ggg;

	auto injector = di::make_injector(
		di::bind<IView>().to<View>()
	);

	
	EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}