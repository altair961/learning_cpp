#include "../std_lib_facilities.h"

int square(int argument)
{
	int square = 0;
	for (int i = 0; i < argument; ++i)
	{
		square += argument;
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