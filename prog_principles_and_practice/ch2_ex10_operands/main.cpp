#include "../PPPheaders.h"

int main()
{
    string operation = "";
    double operand1 = 0.0;
    double operand2 = 0.0;
    double result = 0.0;

    cout << "Enter operation followed by two operands: ";
    cin >> operation >> operand1 >> operand2;

    if(operation == "+" || operation == "plus")
    {
        result = operand1 + operand2;
    } else if(operation == "-" || operation == "minus") {
        result = operand1 - operand2;
    } else if(operation == "*" || operation == "mul") {
        result = operand1 * operand2;
    } else if(operation == "/" || operation == "div") {
        result = operand1 / operand2;
    }

    cout << "result: " << result;

    return 0;
}
