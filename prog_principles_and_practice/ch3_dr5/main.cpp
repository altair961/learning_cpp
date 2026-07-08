#include "../PPPheaders.h"

double absolute(double input) {
    return (input < 0) ? -input : input;
}

int main()
{
    double a, b = 0.0;
    while(cin >> a >> b) {
        double smaller = a;
        double larger = b;

        if(a > b) {
            larger = a;
            smaller = b;
        }

        if(a != b) {
            cout << "The smaller number is: " << smaller << '\n'
                << "and the larger number is: " << larger;

            if(absolute(a - b) < 1.0/100)
                cout << "\nthe numbers are almost equal\n";

        } else {
            cout << "the numbers are equal\n";
        }
    }
    return 0;
}
