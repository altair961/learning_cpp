// Solution for exercise 3.10
// This program takes an operation followed by two operands
// and outputs the result. For example: + 100 3.14

#include "../std_lib_facilities.h"

int main()
{
  string operation = "";
  double operand1 = 0;
  double operand2 = 0;
  double result = 0;
  cout << "Please, enter an operation followed by two operands," << "\n" << "separated by spaces: ";
  cin >> operation >> operand1 >> operand2;

  if (operation == "+" || operation == "plus") {
      result = operand1 + operand2;
  } 
  if (operation == "-" || operation == "minus") {
    result = operand1 - operand2;
  }
  if (operation == "*" || operation == "mul") {
    result = operand1 * operand2;
  }
  if (operation == "/" || operation == "div") {
    result = operand1 / operand2;
  }
    
  cout << "Result: " << result << "\n";
  
  return 0;
}
