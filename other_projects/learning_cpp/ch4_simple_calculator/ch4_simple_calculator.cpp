// ch4_simple_calculator.cpp : Defines the entry point for the console application.
// This program performs as a very simple calculator

#include "stdafx.h"
#include "../std_lib_facilities.h"


double first_operand = 0.0;
double second_operand = 0.0;
char operator_sign;
string operation_name = "";
double result = 0.0;

int main()
{
	cout << "Please, provide first operand. It should be real number: ";
	cin >> first_operand;
	cout << endl << "Now, provide the second operand, also real number: ";
	cin >> second_operand;
	cout << endl << "Now type-in a character representing operation: ";
	cin >> operator_sign;

	switch (operator_sign)
	{
	case '+':
		result = first_operand + second_operand;
		operation_name = "sum";
		break;
	case '-':
		result = first_operand - second_operand;
		operation_name = "subtraction";
		break;
	case '*':
		result = first_operand * second_operand;
		operation_name = "multiplication";
		break;
	case '/':
		result = first_operand / second_operand;
		operation_name = "division";
		break;
	default:
		cout << "Unknown operator, please provide +, -, * or /" << endl;
		break;
	}

	cout << "The " << operation_name << " of " 
		 << first_operand  << " and " 
		 << second_operand << " is " 
		 << result << endl;

	keep_window_open();
    return 0;
}

