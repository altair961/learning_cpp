// ch3_odd_even_tester.cpp : Defines the entry point for the console application.
// Solution for exercise 3.8.
// This program checks whether an inputted integer is even or odd

#include "stdafx.h"
#include "../std_lib_facilities.h"


int main()
{
	int val;
	cout << "Please, enter an integer: ";
	cin >> val;
	if (val % 2 == 0) {
		cout << "The value " << val << " is even number.\n";
	}
	else {
		cout << "The value " << val << " is odd number.\n";
	}

	keep_window_open();
	return 0;
}
