#include "../std_lib_facilities.h"

int main()
{
	int i = 0;
	while (i < 255)
	{
		cout << i << '\t' << (char)i << '\n';
		++i;
	}
}