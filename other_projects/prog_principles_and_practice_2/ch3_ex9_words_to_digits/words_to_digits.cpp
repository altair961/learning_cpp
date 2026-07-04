// This program converts spelled-out numbers such as "zero" and "two" into digits
#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter a spelled-out number such as zero or two (followed by 'enter'): " << endl;
	string input = "";
	cin >> input;

	if (input == "zero")
		cout << "You typed: 0" << endl;

	else if (input == "one")
		cout << "You typed: 1" << endl;

	else if (input == "two")
		cout << "You typed: 2" << endl;

	else if (input == "three")
		cout << "You typed: 3" << endl;

	else 
		cout << "not a number I know.";
}