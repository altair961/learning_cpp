// ch3_name_and_age.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\std_lib_facilities.h"


int main()
{
	cout << "Please enter your name and age in years\n";
	string first_name = "???";
	double age = -1;
	cin >> first_name >> age;
	cout << "Hello, " << first_name << " (age " << age * 12 << " months)\n";

	keep_window_open();
	return 0;
}
