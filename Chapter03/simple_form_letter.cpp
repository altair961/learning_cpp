#include "..\std_lib_facilities.h"
int main()
{
	cout << "Please enter the name of the person you want write to\n";
	string first_name = "???";
	double age = -1;
	cin >> first_name;
	cout << "Dear " << first_name << ",\n\n";
	cout << "How are you? I am fine. \nI miss you.";
}
