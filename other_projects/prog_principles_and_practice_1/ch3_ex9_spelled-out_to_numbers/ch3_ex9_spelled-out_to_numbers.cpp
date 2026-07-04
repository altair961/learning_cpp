#include "../std_lib_facilities.h"
#include <iostream>

int ConvertSpelledOutToNumber(string spelledOutNumber)
{
	int number = -1;

	if (spelledOutNumber == "zero")
		number = 0;

	if (spelledOutNumber == "one")
		number = 1;

	if (spelledOutNumber == "two")
		number = 2;

	if (spelledOutNumber == "three")
		number = 3;

	return number;
}

int main()
{
	cout << "Please enter a spelled-out number: ";
	string spelledOutNumber = "";
	cin >> spelledOutNumber;

	int number = -1;
	number = ConvertSpelledOutToNumber(spelledOutNumber);

	if (number == -1)
		cout << "Not a number I know." << endl;

	if(number != -1)
		cout << "You have typed: " << number;
}
