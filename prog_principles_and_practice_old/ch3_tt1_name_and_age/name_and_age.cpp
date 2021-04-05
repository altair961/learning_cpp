// read name and age
#include "../std_lib_facilities.h"

int main()
{
	cout << "Please enter your first name and age\n";
	string first_name = "???"; // ('???” means “don’t know the name”)
	double age_years = -1; // integer variable (–1 means “don’t know the age”)
	cin >> first_name >> age_years; // read a string followed by an integer
	double age_months = age_years * 12;
	cout << "Hello, " << first_name << " (age " << age_months << " months " << ")\n";
}