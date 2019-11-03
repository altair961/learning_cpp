// This program writes a letter based on user input

#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter first integer, (followed by 'enter'): ";
	int val1;
	cin >> val1;

	cout << "Enter second integer: ";
	int val2;
	cin >> val2;

	int smaller{ 0 };
	int larger{ 0 };

	if (val1 < val2) 
	{
		smaller = val1;
		larger = val2;
	}

	if (val2 < val1)
	{
		smaller = val2;
		larger = val1;
	}

	if (val1 == val2)
	{
		smaller = larger = val1;
	}

	int sum{ val1 + val2 };
	int diff{ larger - smaller };
	int product{ val1 * val2 };

	double ratio{ (double)val1 / (double)val2 };

	if(val1 == val2)
		cout << endl << "The numbers a same.";

	if (val1 != val2) 
	{
		cout << endl << smaller << " is the smaller number.";
		cout << endl << larger << " is the larger number.";
	}

	cout << endl << sum << " is the sum.";
	cout << endl << diff << " is the difference.";
	cout << endl << product << " is the product." << endl;
}