#include "../PPPheaders.h"

double toMeters(double input, const string& unit) {
    double result = input;
    if(unit == "cm") {
        result = 0.01 * input;
    } else if(unit == "in") {
        result = 0.0254 * input;
    } else if(unit == "ft") {
        result = 0.3048 * input;
    }
    return result;
}

int main()
{
    double input = 0.0;
    string unit = "";
    cin >> input >> unit;
    input = toMeters(input, unit);
    cout << input << unit << " the smallest and the largest so far\n";
    double larger = input;
    double smaller = input;

    while(cin >> input >> unit) {
        input = toMeters(input, unit);
        if(input > larger) {
            larger = input;
            cout << input << unit << " the largest so far: " << larger << '\n';
        } else if(input < smaller) {
            smaller = input;
            cout << input << unit << " the smallest so far: " << smaller << '\n';
        }
    }
    return 0;
}
