#include "../std_lib_facilities.h"

int main()
{
	double x{ 2.7 }; // OK
	int y{ x }; // error: double -> int might narrow
	int a{ 1000 }; // OK
	char b{ a };

	double x = 2.7;
	int y = x;
	int a = 1000;
	char b = a;
}