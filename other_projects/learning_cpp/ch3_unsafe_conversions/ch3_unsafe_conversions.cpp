// ch3_unsafe_conversions.cpp : Defines the entry point for the console application.
// This program demonstrates unsafe conversions

#include "stdafx.h"
#include "..\std_lib_facilities.h"


int main() {

	cout << "Please, enter a double number to see its representations in different built-in types" << endl;
	cout << "To finish the input type |" << endl;
	double d = 0;
	while (cin >> d) {
		int i = d;
		char c = i;
		int i2 = c;
		cout << " d==" << d
			<< " i==" << i
			<< " i2==" << i2
			<< " char(" << c << ")\n";
	}

	keep_window_open();
}
