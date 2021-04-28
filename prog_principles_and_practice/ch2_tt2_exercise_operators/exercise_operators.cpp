#include "../std_lib_facilities.h"

int main()
{
	cout << "Please enter an integer value: ";
	int inputInt;
	cin >> inputInt;
	double inputDouble = inputInt;

	cout << "n == " << inputInt
		<< "\nn+1 == " << inputInt+1
		<< "\nthree times n == " << 3*inputInt
		<< "\ntwice n == " << inputInt+inputInt
		<< "\nsquared n == " << inputInt*inputInt
		<< "\nhalf of n == " << inputInt/2
		<< "\nsquare root of n == " << sqrt(inputDouble)
		<< '\n';
}
