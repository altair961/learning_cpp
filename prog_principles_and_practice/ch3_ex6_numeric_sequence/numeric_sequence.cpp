// This program orders sequence of numbers input by user

#include "../std_lib_facilities.h"

int min(int first, int second);
int max(int first, int second);

int main()
{
	cout << "Enter three numbers (followed by 'enter'): " << endl;
	int val1;
	int val2;
	int val3;
	//      3       2      2
	cin >> val1 >> val2 >> val3;

	if (val1 <= val2) 
	{
		if(val1 < val3)
		{
			cout << val1 << min(val2, val3) << max(val2, val3) << endl;
		}
	}

	if (val2 < val1)
	{
		if (val2 < val3)
		{
			cout << val2 << min(val1, val3) << max(val1, val3) << endl;
		}
	}

	if(val3 <= val1)
	{
		if (val3 <= val2)
		{
			cout << val3 << min(val1, val2) << max(val1, val2) << endl;
		}
	}
}

int min(int first, int second)
{
	if (first < second) {
		return first;
	}
	if (second < first) {
		return second;
	}
	if (first == second) {
		return first;
	}
	return -1;
}

int max(int first, int second)
{
	if (first > second) {
		return first;
	}
	if (second > first) {
		return second;
	}
	if (first == second) {
		return first;
	}
	return -1;
}