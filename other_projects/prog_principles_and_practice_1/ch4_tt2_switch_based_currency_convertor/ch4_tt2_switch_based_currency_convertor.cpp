#include "..\std_lib_facilities.h"

int main()
{
    constexpr double dollars_per_yen = 0.0073;
    constexpr double dollars_per_euro = 1;
    constexpr double dollars_per_pound = 1.18;
    constexpr double dollars_per_ruble = 0.017;
    constexpr double dollars_per_danish_krone = 0.13;
    constexpr double dollars_per_yuan = 0.15;

    cout << "Please enter amount of money: ";
    string usrInput = "";
    cin >> usrInput;
    double moneyAmount = 0.0;

    try {
        moneyAmount = std::stod(usrInput);
    }
    catch (const std::invalid_argument& e) {
        cout << "Could not convert input value to double.\n";
        return -1;
    }

    cout << "Now enter a currency name (JPY, EUR, GBP, RUB, DKK or CNY): ";
    string currName = "";
    cin >> currName;

    string currNameLower = "";
    for (char character : currName)
    {
        char characterLower = std::tolower(character);
        currNameLower.push_back(characterLower);
    }

    currName = currNameLower;

    double dollars = 0.0;

    switch (currName[0])
    {
    case 'j':
        dollars = moneyAmount * dollars_per_yen;
        cout << moneyAmount << " JPY == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    case 'e':
        dollars = moneyAmount * dollars_per_euro;
        cout << moneyAmount << " EUR == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    case 'g':
        dollars = moneyAmount * dollars_per_pound;
        cout << moneyAmount << " GBP == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    case 'r':
        dollars = moneyAmount * dollars_per_ruble;
        cout << moneyAmount << " RUB == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    case 'd':
        dollars = moneyAmount * dollars_per_danish_krone;
        cout << moneyAmount << " DKK == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    case 'c':
        dollars = moneyAmount * dollars_per_yuan;
        cout << moneyAmount << " CNY == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
        break;
    default:
        cout << "Sorry, it's not a currency name I know!\n";
        break;
    };
}