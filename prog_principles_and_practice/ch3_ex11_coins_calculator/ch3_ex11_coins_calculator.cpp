#include "../std_lib_facilities.h"

int nickelsToCents(int nickels)
{
    int cents = nickels * 5;
    return cents;
}

int dimesToCents(int dimes)
{
    int cents = dimes * 10;
    return cents;
}

int quartersToCents(int quarters)
{
    int cents = quarters * 25;
    return cents;
}

int halfDollarsToCents(int halfDollars)
{
    int cents = halfDollars * 50;
    return cents;
}

int main()
{
    cout << "How many pennies do you have? ";
    int pennies = 0;
    cin >> pennies;

    cout << "How many nickels do you have? ";
    int nickels = 0;
    cin >> nickels;

    cout << "How many dimes do you have? ";
    int dimes = 0;
    cin >> dimes;

    cout << "How many quarters do you have? ";
    int quarters = 0;
    cin >> quarters;

    cout << "How many half dollars do you have? ";
    int halfDollars = 0;
    cin >> halfDollars;

    cout << endl << "You have " << pennies << " pennies.";
    cout << endl << "You have " << nickels << " nickels.";
    cout << endl << "You have " << dimes << " dimes.";
    cout << endl << "You have " << quarters << " quarters.";
    cout << endl << "You have " << halfDollars << " half dollars.";

    int nickelsInCents = nickelsToCents(nickels);
    int dimesInCents = dimesToCents(dimes);
    int quartersInCents = quartersToCents(quarters);
    int halfDollarsInCents = halfDollarsToCents(halfDollars);
    
    int totalValueInCents = pennies + nickelsInCents + dimesInCents + quartersInCents + halfDollarsInCents;

    cout << endl << "The value of all of your coins is " << totalValueInCents << " cents." << endl;
}