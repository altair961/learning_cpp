// This progarm uses an implementation of square function
// that calculates the result without multiplication

#include "../std_lib_facilities.h"

int Square(int x);

int main()
{
	for (int i = 0; i < 100; i++)
	{
		cout << i << "\t" << Square(i) << endl;
	}
}

int Square(int x)
{
	int result = 0;
	for (int i = 0; i < x; i++)
	{
		result += x;
	}

	return result;
}
