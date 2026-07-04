#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter an int number, separated by enter: ";
    int number;
    cin >> number;
    int remainder;
    remainder = number % 2;

    if (remainder == 1)
        cout << "The number: " << number << " is odd.\n";

    if (remainder == 0)
        cout << "The number: " << number << " is even.\n";

    return 0;
}
