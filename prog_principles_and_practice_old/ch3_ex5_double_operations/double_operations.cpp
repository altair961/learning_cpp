// This program determines the smaller, larger, sum, difference, product, 
// and ratio of two floating-point values and reports them to the user.

#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter first floating-point number (followed by 'enter'): ";
	double val1;
	cin >> val1;

	cout << "Enter second floating-point: ";
	double val2;
	cin >> val2;

	double smaller{ 0.0 };
	double larger{ 0.0 };

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

	double sum{ val1 + val2 };
	double diff{ larger - smaller };
	double product{ val1 * val2 };

	double ratio{ val1 / val2 };

	if (val1 == val2)
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