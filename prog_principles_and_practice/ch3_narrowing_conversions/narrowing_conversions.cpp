// This program demonstrate, that {} initialization outlaws narrowing conversions
// and produces compile time error. Uncomment C++11 initialization to see the error
#include "../std_lib_facilities.h"

int main()
{
	// C++11 assignment
	//double x{ 2.7 }; // OK
	//int y{ x }; // error: double -> int might narrow
	//int a{ 1000 }; // OK
	//char b{ a };

	// old style assignment
	double x = 2.7;
	int y = x;
	int a = 1000;
	char b = a;
}