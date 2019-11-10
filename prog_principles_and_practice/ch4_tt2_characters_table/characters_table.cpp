// This progarm prints out a table of characters from a to z
// each carachter is actually an int so we can increment 97
// which means 'a' by 1 and get 98 which means 'b' and so on.

#include "../std_lib_facilities.h"

int main()
{
	for (char c = 'a'; c <= 122; c++)
	{
		cout << c << endl;
	}
}