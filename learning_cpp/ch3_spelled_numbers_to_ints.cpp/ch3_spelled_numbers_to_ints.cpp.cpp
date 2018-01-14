// ch3_spelled_numbers_to_ints.cpp.cpp : Defines the entry point for the console application.
// Solution for exercise 3.9
// This program converts inputted numbers into spelled-out numbers
// such as "zero" and "two" into digits, such as 0 and 2

#include "stdafx.h"
#include "../std_lib_facilities.h"


int main()
{
	string val;
	cout << "Please, enter a spelled-out number: ";
	cin >> val;

	if (val == "zero" ||
		val == "one" ||
		val == "two" ||
		val == "three" ||
		val == "four") {
		if (val == "zero") cout << 0 << "\n";
		if (val == "one") cout << 1 << "\n";
		if (val == "two") cout << 2 << "\n";
		if (val == "three") cout << 3 << "\n";
		if (val == "four") cout << 4 << "\n";
	}
	else
		cout << "Not a number I know." << "\n";

	keep_window_open();
	return 0;
}
