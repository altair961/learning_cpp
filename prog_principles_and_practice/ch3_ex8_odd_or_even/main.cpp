#include "../PPPheaders.h"

int main()
{
    int input = 0;
    cout << "Enter an integer value to see if it is odd or even: ";
    cin >> input;

    if(input % 2 == 0)
    {
        cout << "The value " << input << " is an even number";
    } else {
        cout << "The value " << input << " is an odd number";
    }

    return 0;
}
