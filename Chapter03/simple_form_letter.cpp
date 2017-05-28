#include "..\std_lib_facilities.h"
int main()
{
	cout << "Please enter the name of the person you want write to\n";
	string first_name = "???";
	double age = -1;
	char friend_sex = 0;
	string friend_name = "???";
	cin >> first_name;
	cout << "\nEnter the name of your mutual friend/n";
	cin >> friend_name;
	cout << "Dear " << first_name << ",\n\n";
	cout << "How are you? I am fine. \nI miss you.\n\n";
	cout << "Have you seen " << friend_name << " lately?";
}
