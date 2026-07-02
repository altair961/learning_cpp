#include "../std_lib_facilities.h"

vector<string> GetUserInputs() 
{
    string input;
    vector<string> inputs;

    for (int i = 0; i <= 2; i++)
    {
        cin >> input;
        inputs.push_back(input);
    }

    return inputs;
}

double Add(double firstOperand, double secondOperand)
{
    double result = firstOperand + secondOperand;
    return result;
}

double Subtract(double firstOperand, double secondOperand)
{
    double result = firstOperand - secondOperand;
    return result;
}

double Divide(double firstOperand, double secondOperand)
{
    double result = firstOperand / secondOperand;
    return result;
}

double Multiply (double firstOperand, double secondOperand)
{
    double result = firstOperand * secondOperand;
    return result;
}

double GetRemainder(double firstOperand, double secondOperand)
{
    int firstOperInt = firstOperand;
    int secondOperInt = secondOperand;
    double result = firstOperInt % secondOperInt;
    return result;
}

double PerformOperation(string operatorStr, double firstOperand, double secondOperand, bool &isSuccessful)
{
    double result = 0.0;
    if (operatorStr == "+") 
    {
        result = Add(firstOperand, secondOperand);
        isSuccessful = true;
        return result;
    }

    if (operatorStr == "-")
    {
        result = Subtract(firstOperand, secondOperand);
        isSuccessful = true;
        return result;
    }

    if (operatorStr == "/")
    {
        result = Divide(firstOperand, secondOperand);
        isSuccessful = true;
        return result;
    }

    if (operatorStr == "*")
    {
        result = Multiply(firstOperand, secondOperand);
        isSuccessful = true;
        return result;
    }

    if (operatorStr == "%")
    {
        result = GetRemainder(firstOperand, secondOperand);
        isSuccessful = true;
        return result;
    }

    isSuccessful = false;
    cout << "Error: the first token is not known operator." << endl;
    return 0.0;
}

int main()
{
    cout << "Please specify operation followed by two operands separated by spaces. \n";
    vector<string> userInputs = GetUserInputs();
    
    string operatorStr = userInputs[0];
    
    string secondToken = userInputs[1];
    double firstOperand = stod(secondToken);

    string thirdToken = userInputs[2];
    double secondOperand = stod(thirdToken);

    bool isSuccessful = false;
    double result = PerformOperation(operatorStr, 
        firstOperand, secondOperand, isSuccessful);

    if (isSuccessful)
    {
        cout << "result: " << result << endl;
        return 0;
    }

    cout << "Operation was not successful. Exiting..." << endl;
    cout << "\n\n";
    return -1;
}