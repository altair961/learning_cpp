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

bool IsDiffSmall(double num1, double num2)
{
	double smaller = GetSmallest(num1, num2);
	double larger = GetLargest(num1, num2);
	double difference = larger - smaller;
	double diffThreshold = 1.0 / 100;

	if (difference < diffThreshold)
		return true;

	return false;
}

int main()
{
	cout << "Please, provide a double number or \"pipe\"-sign \"|\" to terminate input: " << "\n";
	string input;
	double prevNum = 0.0;
	while (cin >> input && input != "|")
	{
		double newNum = stod(input);

		cout << "\nnew number: " << newNum << "\n";
		cout << "previous number: " << prevNum << "\n";

		if (newNum == prevNum)
			cout << "The numbers are equal\n";

		if (newNum != prevNum)
		{
			double smaller = GetSmallest(newNum, prevNum);
			double larger = GetLargest(newNum, prevNum);

			cout << "The smallest so far: " << smaller << "\n";
			cout << "The largest so far: " << larger << "\n";

			bool isDiffSmall = IsDiffSmall(newNum, prevNum);

			if (isDiffSmall)
				cout << "The numbers are almost equal.\n";
		}

		prevNum = newNum;
	}
}