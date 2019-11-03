// This program converts miles to kilometers

#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter the amount of miles to convert to kilometers, (followed by 'enter'): ";
	double miles;
	cin >> miles;

	double kilometers = miles * 1.609;
	cout << endl << "There are " << kilometers << " kilometers in " << miles << " miles." << endl;
}