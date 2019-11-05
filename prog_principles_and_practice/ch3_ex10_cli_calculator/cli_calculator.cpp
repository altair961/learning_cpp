// This program is a command line interface calculator

#include "../std_lib_facilities.h"

string toLowerCase(string s);

int main()
{
	cout << "Enter an operator and two operands like this: + 100 3.14"
		<< endl << "then press 'enter' to get the result of the calculation:";

	string operation{ "" };
	double operand1{ 0.0 };
	double operand2{ 0.0 };
	double result{ 0.0 };

	cin >> operation >> operand1 >> operand2;

	operation = toLowerCase(operation);

	if (operation == "+" || operation == "plus")
		result = operand1 + operand2;

	if (operation == "-" || operation == "minus")
		result = operand1 - operand2;

	if (operation == "*" || operation == "mul")
		result = operand1 * operand2;

	if (operation == "/" || operation == "div")
		result = operand1 / operand2;

	cout << "The result is: " << result;
}

string toLowerCase(string s)
{
	string result = "";
	for (char ch : s)
	{
		result += tolower(ch);
	}

	return s;
}

/*
Write a program that takes an operation followed by
two operands and outputs the result. For example:

+ 100 3.14
* 4 5

Read the operation into a string called
operation and use an if-statement to figure out which
operation the user wants, for example,
if (operation=="+").
Read the operands into variables of type double.
Implement this for operations called +, –, *, /,
plus, minus, mul, and div with their obvious meanings.
*/