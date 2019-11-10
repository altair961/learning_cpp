// convert from yen, euro, pounds to dollars
// a suffix 'y', 'e' or 'p' indicates the unit of the input
// any other suffix is an error

#include "../std_lib_facilities.h"

string toLowerCase(string s);

int main()
{
	constexpr double dollars_per_yen = 0.0092;
	constexpr double dollars_per_euro = 1.10;
	constexpr double dollars_per_pound = 1.28;
	constexpr double dollars_per_renminbi = 0.14;
	constexpr double dollars_per_kroner = 0.11;

	cout << "Please enter amount of money followed by space/enter/tab and a unit (y for yen, e for euro or p for pounds):\n";
	double money_amount = 0.0;
	char unit = ' ';
	string unit_input = " ";

	cin >> money_amount >> unit_input;
	unit_input = toLowerCase(unit_input);
	unit = unit_input.at(0);
	
	switch (unit) {
	case 'y':
		cout << money_amount << " yen == $" << dollars_per_yen * money_amount << endl;
		break;
	case 'e':
		cout << money_amount << " euro == $" << dollars_per_euro * money_amount << endl;
		break;
	case 'p':
		cout << money_amount << " pounds == $" << dollars_per_pound * money_amount << endl;
		break;
	case 'r':
		cout << money_amount << " renminbis == $" << dollars_per_renminbi * money_amount << endl;
		break;
	case 'k':
		cout << money_amount << " kroner == $" << dollars_per_pound * money_amount << endl;
		break;

	default:
		cout << "Sorry, I don't know a unit called '" << unit << "'\n";
		break;
	}

	return 0;
}

string toLowerCase(string s)
{
	string result = "";
	for (char ch : s)
		result += tolower(ch);

	return s;
}