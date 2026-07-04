#include <iostream>

using namespace std;

int main()
{
    string input;
    cout << "Enter spelled-out number: ";
    cin >> input;

    if(input == "zero")
    {
        cout << "value: " << 0;
    } else if(input == "one") {
        cout << "value: " << 1;
    } else if(input == "two") {
        cout << "value: " << 2;
    } else if (input == "three") {
        cout << "value: " << 3;
    } else if (input == "four") {
        cout << "value: " << 2;
    } else {
        cout << "Not a number I know.";
    }

    return 0;
}
