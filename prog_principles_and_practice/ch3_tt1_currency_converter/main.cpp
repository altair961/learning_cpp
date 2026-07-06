#include "../PPPheaders.h"

int main()
{
    char unit = '_';
    double sum = 0;
    constexpr double yen_per_usd = 164.54;
    constexpr double kroner_per_usd = 9.64;
    constexpr double pounds_per_usd = 0.75;

    cout << "Please enter sum, followed by unit."
        <<"\n y - for yen, k - for kroner, p - for pounds: ";
    cin >> sum >> unit;

    if(unit == 'y')
    {
        cout << sum << " yen == $" << sum / yen_per_usd;
    } else if(unit == 'k') {
        cout << sum << " kroner == $" << sum / kroner_per_usd;
    } else if(unit == 'p') {
        cout << sum << " pounds == $" << sum / pounds_per_usd;
    } else {
        cout << "Sorry, I don't know a unit called " << unit;
    }

    return 0;
}
