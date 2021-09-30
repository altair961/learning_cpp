#include "pch.h"
#include "MathLibrary.h"
#include "MathLibrary2.h"

TEST(TestCaseName, When_AddVisualObject_Invoked_Should_InvokeDraw) {
	double a = 7.4;
	int b = 99;

	auto r = MathLibrary::Arithmetic::Add(a, b);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}