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