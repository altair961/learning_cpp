// This program writes a letter based on user input

#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'): ";
	string first_name;
	cin >> first_name;

	cout << "Enter age of the person: ";
	int age{ 0 };
	cin >> age;

	cout << "Enter the name of another friend: ";
	string friend_name;
	cin >> friend_name;

	cout << "Enter gender of the friend (m - for male or f for female): ";
	char friend_sex{ 0 };
	cin >> friend_sex;

	cout << endl
		<< '\t' << "Dear " << first_name << "," << endl
		<< "How are you? " << "Is everything alright? " << "I'm fine. I miss you." << endl
		<< "Have you seen " << friend_name << " lately?" << endl << endl;

	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me." << endl;

	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me." << endl;

	cout << "I hear you just had a birthday and you are " << age << " years old." << endl;

	if (age == 0 || age >= 110)
		simple_error("you're kidding!");

	if (age < 12)
		cout << "Next year you will be " << age + 1 << "." << endl;

	if (age == 17)
		cout << "Next year you will be able to vote." << endl;

	if (age > 70)
		cout << "I hope you are enjoying retirement." << endl;

	cout << endl << endl << "Yours sincerely, John" << endl;
}