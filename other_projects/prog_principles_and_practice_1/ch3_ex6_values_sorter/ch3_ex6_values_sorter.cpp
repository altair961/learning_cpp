#include "../std_lib_facilities.h"

int main() {
	int val1 = 0;
	int val2 = 0;
	int val3 = 0;
	cout << "Please enter three values, separated by enter: \n";
	cin >> val1;
	cin >> val2;
	cin >> val3;
	
	if(val1 <= val2 && val1 <= val3) // val1 is smallest
	{ 
		cout << val1 << ", ";
		if(val2 <= val3)
		{
			cout << val2 << ", " << val3 << "\n";
		} else if (val3 < val2)
		{
			cout << val3 << ", " << val2 << "\n";
		}
	} else if(val2 < val1 && val2 < val3) // val2 is smallest 
	{
		cout << val2 << ", ";
		if(val1 <= val3)
		{
			cout << val1 << ", " << val3 << "\n";
		} else if(val3 < val1)
		{
			cout << val3 << ", " << val1 << "\n";
		}
	} else if(val3 < val1 && val3 < val2) // val3 is smallest
	{
		cout << val3 << ", ";
		if(val1 <= val2)
		{
			cout << val1 << ", " << val2 << "\n";
		} else if(val2 < val1)
		{
			cout << val2 << ", " << val1 << "\n";
		}
	}

	return 0;
}
