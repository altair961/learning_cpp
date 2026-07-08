#include "../PPPheaders.h"

int main()
{
    double input = 0.0;
    cin >> input;
    cout << input << " the smallest and the largest so far\n";
    double larger = input;
    double smaller = input;

    while(cin >> input) {
        if(input > larger) {
            larger = input;
            cout << input << " the largest so far: " << larger << '\n';
        } else if(input < smaller) {
            smaller = input;
            cout << input << " the smallest so far: " << smaller << '\n';
        }
    }
    return 0;
}
