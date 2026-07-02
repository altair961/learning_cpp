// This program determines if the input value is odd or even
#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter an integer number (followed by 'enter'): " << endl;
	int input{ 0 };
	cin >> input;

	if (input % 2 == 0)
		cout << endl << "The value " << input << " is an even number." << endl;

	if (input % 2 == 1)
		cout << endl << "The value " << input << " is an odd number." << endl;
}