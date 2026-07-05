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

    if(pennies != 0)
        cout << "\nYou have " << pennies << " pennies.\n";
    if(nickels != 0)
        cout << "You have " << nickels << " nickels.\n";
    if(dimes != 0)
        cout << "You have " << dimes << " dimes.\n";
    if(quarters !=0)
        cout << "You have " << quarters << " quarters.\n";
    if(half_dollars != 0)
        cout << "You have " << half_dollars << " half-dollars.\n";
    if(one_dollars != 0)
        cout << "You have " << one_dollars << " one-dollars.\n";

    cout << "The value of all your coins is " << total_cents << " cents.";

    return 0;
}
