#include "../std_lib_facilities.h"

double GetSmallest(double first, double second)
{
	if (first < second)
		return first;

	return second;
}

double GetLargest(double first, double second)
{
	if (first > second)
		return first;

	return second;
}

int main()
{
	cout << "Please, provide two double numbers or \"pipe\"-sign \"|\" to terminate input: " << "\n";
	string numStr1, numStr2;
	while (cin >> numStr1 && numStr1 != "|" && cin >> numStr2 && numStr2 != "|")
	{
		double num1 = stod(numStr1);
		double num2 = stod(numStr2);

		cout << "\n";
		cout << "num1: " << num1 << "\n";
		cout << "num2: " << num2 << "\n\n";

		if (num1 == num2)
			cout << "The numbers are equal\n";

		if (num1 != num2)
		{
			cout << "The smaller number is: " << GetSmallest(num1, num2) << "\n";
			cout << "The larger number is: " << GetLargest(num1, num2) << "\n";
		}
	}
}