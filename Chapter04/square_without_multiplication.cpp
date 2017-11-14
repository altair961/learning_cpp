#include "..\std_lib_facilities.h"

int Square(int);

int main()
{
	int inputValue;
	cout << "Enter a value: ";
	cin >> inputValue;
	cout << "Square of "
		 << inputValue
		 << " is: "
		 << Square(inputValue);
}

int Square(int operand)
{
	int result = 0;
	for(int i = 0; i < operand; i++)
	{
		result += operand;
	}
	return result;
}
