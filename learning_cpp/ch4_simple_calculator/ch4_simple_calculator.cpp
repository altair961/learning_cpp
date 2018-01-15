// ch4_simple_calculator.cpp : Defines the entry point for the console application.
// This program performs as a very simple calculator

#include "stdafx.h"
#include "../std_lib_facilities.h"


double first_operand = 0.0;
double second_operand = 0.0;

int main()
{
	cout << "Please, provide first operand. It should be real number: " << endl;
	cin >> first_operand;
	cout << "Now, provide the second operand, also real number:" << endl;
	cin >> second_operand;

    return 0;
}

