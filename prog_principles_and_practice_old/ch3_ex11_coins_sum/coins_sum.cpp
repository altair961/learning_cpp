// This program calculates the sum of input coins values

#include "../std_lib_facilities.h"

int main()
{
	int pennies{ 0 };
	cout << "How many pennies do you have? ";
	cin >> pennies;

	int nickels{ 0 };
	cout << endl << "How many nickels do you have? ";
	cin >> nickels;

	int dimes{ 0 };
	cout << endl << "How many dimes do you have? ";
	cin >> dimes;

	int quarters{ 0 };
	cout << endl << "How many quarters do you have? ";
	cin >> quarters;

	int half_dollars{ 0 };
	cout << endl << "How many half dollars do you have? ";
	cin >> half_dollars;

	int one_dollar{ 0 };
	cout << endl << "How many one-dollar coins do you have? ";
	cin >> one_dollar;

	cout << endl << "You have " << pennies << ((pennies > 1) ? " pennies" : " penny");
	cout << endl << "You have " << nickels << ((nickels > 1) ? " nickels" : " nickel");
	cout << endl << "You have " << dimes << ((dimes > 1) ? " dimes" : " dime");
	cout << endl << "You have " << quarters << ((quarters > 1) ? " quarters" : " quarter");
	cout << endl << "You have " << half_dollars << ((half_dollars > 1) ? " half dollars" : " half dollar");

	double result = ((double)one_dollar * 100 + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + pennies) / 100.0;

	cout << endl << endl << "The value of all of your coins is " 
		<< "$" << result << endl;
}