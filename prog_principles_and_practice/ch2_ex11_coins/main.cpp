#include "../PPPheaders.h"

int main()
{
    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int quarters = 0;
    int half_dollars = 0;
    int one_dollars = 0;
    int total_cents = 0;

    cout << "How many pennies do you have?: ";
    cin >> pennies;
    cout << "How many nickels do you have?: ";
    cin >> nickels;
    cout << "How many dimes do you have?: ";
    cin >> dimes;
    cout << "How many quarters do you have?: ";
    cin >> quarters;
    cout << "How many half-dollar coins do you have?: ";
    cin >> half_dollars;
    cout << "How many one-dollar coins do you have?: ";
    cin >> one_dollars;

    total_cents = pennies + nickels * 5 + dimes * 10
        + quarters * 25 + half_dollars * 50 + one_dollars * 100;

    if(pennies == 1)
        cout << "\nYou have " << pennies << " penny.\n";
    else
        cout << "\nYou have " << pennies << " pennies.\n";

    if(nickels == 1)
        cout << "You have " << nickels << " nickel.\n";
    else
        cout << "You have " << nickels << " nickels.\n";

    if(dimes == 1)
        cout << "You have " << dimes << " dime.\n";
    else
        cout << "You have " << dimes << " dimes.\n";

    if(quarters == 1)
        cout << "You have " << quarters << " quarter.\n";
    else
        cout << "You have " << quarters << " quarters.\n";

    if(half_dollars == 1)
        cout << "You have " << half_dollars << " half-dollar coin.\n";
    else
        cout << "You have " << half_dollars << " half-dollar coins.\n";

    if(one_dollars == 1)
        cout << "You have " << one_dollars << " one-dollar coin.\n";
    else
        cout << "You have " << one_dollars << " one-dollar coins.\n";

    cout << "\nThe value of all your coins is $" << total_cents / 100
         << ".";

    if(total_cents % 100 < 10)
        cout << '0';

    cout << total_cents % 100;

    return 0;
}
