#include "../std_lib_facilities.h"

int main()
{
	string input1, input2;
	while (cin >> input1 && input1 != "|" && cin >> input2 && input2 != "|")
	{
		cout << "input1: " << input1 << "\n";
		cout << "input2: " << input2 << "\n";
	}
}