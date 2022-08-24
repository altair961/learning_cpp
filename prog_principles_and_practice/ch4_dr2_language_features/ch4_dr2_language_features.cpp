#include "../std_lib_facilities.h"

int GetSmallest(int first, int second) 
{
	if (first < second)
		return first;

	return second;
}

int GetLargest(int first, int second) 
{
	if (first > second)
		return first;

	return second;
}

int main()
{
	cout << "Please, provide two integer numbers or \"pipe\"-sign \"|\" to terminate input: " << "\n";
	string numStr1, numStr2;
	while (cin >> numStr1 && numStr1 != "|" && cin >> numStr2 && numStr2 != "|")
	{
		int num1 = stoi(numStr1);
		int num2 = stoi(numStr2);

		cout << "\n";
		cout << "num1: " << num1 << "\n";
		cout << "num2: " << num2 << "\n\n";

		cout << "The smaller number is: " << GetSmallest(num1, num2) << "\n";
		cout << "The larger number is: " << GetLargest(num1, num2) << "\n";
	}
}