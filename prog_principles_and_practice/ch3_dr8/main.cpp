#include "../PPPheaders.h"

double to_meters(double input, const string& unit) {
    double meters = input;
    if(unit == "cm") {
        meters = 0.01 * input;
    } else if(unit == "in") {
        meters = 0.0254 * input;
    } else if(unit == "ft") {
        meters = 0.3048 * input;
    }
    return meters;
}

bool is_valid_unit(const string& unit) {
    return unit == "m" ||
            unit == "cm" ||
            unit == "in" ||
            unit == "ft";
}

int main()
{
    double input = 0.0;
    string unit = "";

    while(cin >> input >> unit) {
        if(is_valid_unit(unit))
            break;

        cout << "Illegal unit. Try again.\n";
    }

    if(!cin)
        return 0;

    input = to_meters(input, unit);
    cout << input << "m the smallest and the largest so far\n";
    double larger = input;
    double smaller = input;

    while(cin >> input >> unit) {
        if(!is_valid_unit(unit)) {
            cout << "Illegal unit. Try again.\n";
            continue;
        }

        input = to_meters(input, unit);
        if(input > larger) {
            larger = input;
            cout << input << "m the largest so far: " << larger << '\n';
        } else if(input < smaller) {
            smaller = input;
            cout << input << "m the smallest so far: " << smaller << '\n';
        }
    }
    return 0;
}

















