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

bool isUnitAcceptable(string unit)
{
	if (unit == "cm")
		return true;

	if (unit == "m")
		return true;

	if (unit == "in")
		return true;

	if (unit == "ft")
		return true;

	return false;
}

int main()
{
	string unit;
	double prevInput = 0.0;
	double input;

	cout << "Please, provide a real number, followed by a unit or \"pipe\"-sign \"|\" to terminate input: " << "\n";

	while (cin >> input >> unit && isUnitAcceptable(unit))
	{
		if (input == prevInput)
			cout << "The numbers are equal\n";

		if (input != prevInput)
		{
			double smaller = GetSmallest(input, prevInput);
			double larger = GetLargest(input, prevInput);

			cout << "The smallest so far: " << smaller << " " << unit << "\n";
			cout << "The largest so far: " << larger << " " << unit << "\n";

			bool isDiffSmall = IsDiffSmall(input, prevInput);

			if (isDiffSmall)
				cout << "The numbers are almost equal.\n";
		}
		prevInput = input;
		cout << "\n";
	}
}