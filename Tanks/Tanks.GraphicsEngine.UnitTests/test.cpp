#include "pch.h"
#include "MathLibrary.h"
#include "MathLibrary2.h"

TEST(TestCaseName, TestName) {
	double a = 7.4;
	int b = 99;

	auto r = MathLibrary::Arithmetic::Add(a, b);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName2, TestName2) {
	double a = 7.4;
	int b = 99;

	auto r = MathLibrary2::Arithmetic::Calculate(a);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
