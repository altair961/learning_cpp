#include "..\std_lib_facilities.h"

int main()
{
    constexpr double dollars_per_yen = 0.0073;
    constexpr double dollars_per_euro = 1;
    constexpr double dollars_per_pound = 1.18;
    constexpr double dollars_per_ruble = 0.017;

    cout << "Please enter amount of money: ";
    string usrInput = "";
    cin >> usrInput;
    double moneyAmount = 0.0;

    try {
        moneyAmount = std::stod(usrInput);
    } catch (const std::invalid_argument& e) {
        cout << "Could not convert input value to double.\n";
        return -1;
    }

    cout << "Now enter a currency name (JPY, EUR, GBP or RUB): ";
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
    if (currName == "jpy")
    {
        dollars = moneyAmount * dollars_per_yen;
        cout << moneyAmount << " JPY == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
    }

    if (currName == "eur")
    {
        dollars = moneyAmount * dollars_per_euro;
        cout << moneyAmount << " EUR == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
    }

    if (currName == "gbp")
    {
        dollars = moneyAmount * dollars_per_pound;
        cout << moneyAmount << " GBP == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
    }

    if (currName == "rub")
    {
        dollars = moneyAmount * dollars_per_ruble;
        cout << moneyAmount << " RUB == " << dollars << (dollars == 1 ? " dollar" : " dollars.\n");
    }

    else
        cout << "Not a currency name I know!\n";
}