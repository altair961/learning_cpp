#include "../std_lib_facilities.h"

int square(int x)
{
	int square = 0;
	for (int i = 0; i < x; ++i)
	{
		square += x;
	}

	return square;
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		cout << i << '\t' << square(i) << '\n';
	}
}