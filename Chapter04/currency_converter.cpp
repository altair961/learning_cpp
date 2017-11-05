#include "../std_lib_facilities.h"

int main()
{
  constexpr double yens_per_dollar = 114.07;
  constexpr double euros_per_dollar = 0.86;
  constexpr double pounds_per_dollar = 0.76;
  
  double money_amount = 1;
  char unit = ' ';

  cout << "Please enter amount of money followed by a unit \n(y for yen, e for euros or p for pounds):\n";
  cin >> money_amount >> unit;

  if (unit == 'y')
    cout << money_amount << " yens == " << money_amount / yens_per_dollar << " dollars \n";
  
  else if (unit == 'e')
    cout << money_amount << " euros == " << money_amount / euros_per_dollar << " dollars \n";
  
  else if (unit == 'p')
    cout << money_amount << " pounds == " << money_amount / pounds_per_dollar << " dollars \n";
      
  else
    cout << "Sorry, I don't know a unit called'" << unit << "'\n";
  
  return 0;
}
