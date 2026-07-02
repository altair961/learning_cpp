#include "../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name;
	cin >> first_name;
	cout << "Now please enter the name of the friend:\n";
	string friend_name;
	cin >> friend_name;
	char friend_sex = 0;
	cout << "Enter m if the friend is male and f if the friend is female:\n";
	cin >> friend_sex;
	cout << "Enter the age of the letter recipient:\n";
	int age = -1;
	cin >> age;
	if(age == 0 || age < 0 || age >= 110)
		simple_error("you're kidding!");

	cout << "\nDear, " << first_name << ",\n";
	cout << "How are you? I am fine. I miss you.\n";
	cout << "I have heard, that your project is going to start next week. Congratulations!\n";
	if(friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";

	if(friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";
	
	cout << "I hear you just had a birthday and your are " << age << " years old.\n";

	if(age < 12)
		cout << "Next year you will be " << age+1 << ".\n";

	if(age == 17)
		cout << "Next year you will be able to vote.\n";

	if(age >= 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "\n\nYours sincerely,\n" 
		<< "Renat\n\n";
}
