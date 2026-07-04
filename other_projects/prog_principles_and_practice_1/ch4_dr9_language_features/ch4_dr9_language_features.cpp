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

double getMeters(double number, string unit) 
{
	double conversionRate = 0.0;

	if (unit == "cm")
		conversionRate = 0.01;

	if (unit == "m")
		conversionRate = 1;

	if (unit == "in")
		conversionRate = 0.0254;
	
	if (unit == "ft")
		conversionRate  = 0.3048;

	double resultMeters = number * conversionRate;

	return resultMeters;
}

int main()
{
	string unit;
	double prevInput = 0.0;
	double input;
	double sumMeters = 0.0;
	vector<double> inputNums;
	cout << "Please, provide a real number, followed by a unit or \"pipe\"-sign \"|\" to terminate input: " << "\n";

	while (cin >> input >> unit && isUnitAcceptable(unit))
	{
		inputNums.push_back(input);

		if (input == prevInput)
			cout << "The numbers are equal\n";

		if (input != prevInput)
		{

			double smaller = GetSmallest(input, prevInput);
			double larger = GetLargest(input, prevInput);

			cout << "The smallest so far: " << smaller << "\n";
			cout << "The largest so far: " << larger << "\n";

			bool isDiffSmall = IsDiffSmall(input, prevInput);

			if (isDiffSmall)
				cout << "The numbers are almost equal.\n";
		}
		prevInput = input;
		cout << "\n";
		double meters = getMeters(input, unit);
		sumMeters += meters;
	}

	cout << "\n";
	sort(inputNums);

	double smallest = inputNums.at(0);
	cout << "The smallest number: " << smallest << "\n";

	double largest = inputNums.at(inputNums.size() - 1);
	cout << "The largest number: " << largest << "\n";

	double numOfVals = inputNums.size();
	cout << "The number of values: " << numOfVals << "\n";
	cout << "The sum: " << sumMeters << " meters.\n";
}