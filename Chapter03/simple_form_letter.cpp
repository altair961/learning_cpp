#include "..\std_lib_facilities.h"

int main()
{
	string first_name = "???";
	double age = -1;
	char friend_sex = 0;
	string friend_name = "???";
	
	cout << "Please enter the name of the person you want write to\n";	
	cin >> first_name;
	
	cout << "\nEnter the name of your mutual friend/n";
	cin >> friend_name;
	
	cout << "\nEnter m if the sex of the friend is male and f, if the sex of the friend is female: \n";
	cin >> friend_sex;

	cout << "\nEnter the age of the person you want write to\n";
	
	cout << "Dear " << first_name << ",\n\n";
	cout << "How are you? I am fine. \nI miss you.\n\n";
	cout << "Have you seen " << friend_name << " lately?";

	if(friend_sex == m) {
		cout << "If you see " + friend_name + " please ask him to call me\n";
	}
	
	if(friend_sex == f) {
		cout << "If you see " + friend_name + " please ask her to call me\n";
	}

	cout << "\nI hear you just had a birthday and you are " + age + " years old";

	if((age == 0 || age < 0) || (age == 110) || (age > 110)) {
		simple_error("you're kidding!");
	}

	if(age < 12) {
		cout << "Next year you will be " + age+1 + "\n";
	}

	if(age == 17) {
		cout << "Next year you will be able to vote\n";
	}

	if(age >= 70) {
		cout << "I hope you are enjoying your retirement";
	}

	cout << "Yours sincerely,\n\n\n";
	cout << "John Smith";
}
