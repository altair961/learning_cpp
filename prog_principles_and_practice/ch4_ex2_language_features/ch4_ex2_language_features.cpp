#include "../std_lib_facilities.h"

bool IsEven(int number)
{
	if (number % 2 == 0)
		return true;

	return false;
}

double GetAvg(double num1, double num2)
{
	double average = (num1 + num2) / 2;

	return average;
}

int main()
{
	cout << "Please, provide floating-point numbers and terminate the input with pipe-sign \"|\" when you're done: ";

	vector<double> temps;
	for (double temp; cin>>temp;)
		temps.push_back(temp);

	sort(temps);

	double median = 0;

	bool isEven = IsEven(temps.size());	
	if (isEven)
	{
		int nonZeroBasedIndex1 = temps.size() / 2;
		int zeroBasedIndex1 = nonZeroBasedIndex1 - 1; 
		int zeroBasedIndex2 = zeroBasedIndex1 + 1;
		                            //5.6                   //7.8
		median = GetAvg(temps.at(zeroBasedIndex1), temps.at(zeroBasedIndex2));
	}

	if (!isEven) 
	{
		int nonZeroBasedIndex = (temps.size() + 1) / 2; // 3
		int zeroBasedIndex = nonZeroBasedIndex - 1;
		median = temps[zeroBasedIndex];
	}

	cout << "Median temperature: " << median << "\n";
}