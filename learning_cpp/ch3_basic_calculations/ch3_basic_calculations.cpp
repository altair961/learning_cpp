// ch3_basic_calculations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\std_lib_facilities.h"


int main() {
	double val1 = 0;
	double val2 = 0;
	cout << "Please, enter first floating point number: ";
	cin >> val1;
	cout << "Enter second floating point number: ";
	cin >> val2;

	if (val1 > val2) {
		cout << "The smaller number is: " << val2 << '\n';
		cout << "The larger number is: " << val1 << '\n';
	}
	if (val1 == val2) {
		cout << "There is no smaller or larger number. The numbers are equal" << '\n';
	}
	if (val1 < val2) {
		cout << "The smaller number is: " << val1 << '\n';
		cout << "The larger number is: " << val2 << '\n';
	}
	cout << "The sum of numbers is: " << val1 + val2 << '\n';
	int difference = 0;
	difference = val1 - val2;
	if (difference < 0) {
		difference *= -1;
	}
	cout << "The difference of the two numbers is: " << difference << '\n';
	cout << "The product of the two numbers is: " << val1 * val2 << '\n';
	cout << "The ratio of the two numbers is: " << val1 / val2 << '\n';

	keep_window_open();
}
