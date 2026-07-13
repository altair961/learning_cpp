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

    double sum = 0.0;
    int count = 0;
    vector<double> values;
    input = to_meters(input, unit);
    values.push_back(input);
    sum += input;
    count++;
    cout << input << "m the smallest and the largest so far\n";
    double larger = input;
    double smaller = input;

    while(cin >> input >> unit) {
        if(!is_valid_unit(unit)) {
            cout << "Illegal unit. Try again.\n";
            continue;
        }
        input = to_meters(input, unit);
        values.push_back(input);
        cout << input << "m";
        sum += input;
        count++;
        if(input > larger) {
            larger = input;
            cout << " the largest so far" << '\n';
        } else if(input < smaller) {
            smaller = input;
            cout << " the smallest so far" << '\n';
        } else {
            cout << '\n';
        }
    }

    cout << "Sum: " << sum << " m\n"
         << "largest: " << larger << " m\n"
         << "smallest: " << smaller << " m\n"
         << "number of entered values: " << count << '\n';

    cout << "Values entered:\n";
    sort(values.begin(), values.end());
    for(double value: values) {
        cout << value << " m\n";
    }

    return 0;
}
