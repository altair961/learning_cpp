#include "../std_lib_facilities.h"

int main()
{
	cout << "Please enter your first name and age\n";
	string first_name = "???";
	double ageYears = -1;
	cin >> first_name >> ageYears;
	int ageMonths = -1;
	ageMonths = ageYears * 12;
	cout << "Hello, " << first_name << " (age " << ageMonths << " months)\n";
}
