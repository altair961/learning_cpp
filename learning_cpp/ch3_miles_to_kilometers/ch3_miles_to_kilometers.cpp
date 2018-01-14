// ch3_miles_to_kilometers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\std_lib_facilities.h"


int main() {
	double miles = 0.0;
	double kilometers = 0.0;
	double kilometers_in_mile = 1.609;

	cout << "Please, enter a value in miles to be converted to kilometers: ";
	cin >> miles;

	kilometers = miles * kilometers_in_mile;

	cout << "There are " << kilometers << " kilometers in " << miles << " miles." << endl;

	keep_window_open();
}
