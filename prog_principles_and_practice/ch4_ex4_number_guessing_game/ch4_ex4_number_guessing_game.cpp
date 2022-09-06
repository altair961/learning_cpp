#include "../std_lib_facilities.h"

bool IsInputAllowedAns(char input) 
{
    if (input == 'y')
        return true;

    if (input == 'n')
        return true;

    return false;
}

void HandleInputValidity(char input)
{
    bool isInputAllowedAns = IsInputAllowedAns(input);
    if (isInputAllowedAns == true)
        return;

    cout << "The answer should be either \"y\" for \"yes\" or \"n\" for \"no\" \n"
        << "Exiting...\n";

    exit(-1);
}

vector<int> GetNums()
{
    vector<int> nums;
    for (int i = 1; i <= 100; i++)
        nums.push_back(i);

    return nums;
}

char GetUsersInput()
{
    char input = 0;
    cin >> input;
    HandleInputValidity(input);
    
    return input;
}

int main()
{
    vector<int> numbers = GetNums();

    cout << "Please, think of a number between 1 and 100.\n"
        << "Answer the questions with \"y\" for \"yes\" or \"n\" for \"no\".\n\n";

    cout << "Is the number you are thinking of less than 51? ";
    char input = GetUsersInput();

    if (input == 'y')
    {
        // [1, 50]
        vector<int>::const_iterator first = numbers.begin() + 0;
        vector<int>::const_iterator last = numbers.begin() + 50;
        vector<int> oneToFifty(first, last);

        cout << "Is the number you are thinking of less than 26? ";
        input = GetUsersInput();

        if (input == 'y')
        {
            // [1, 25]
            vector<int>::const_iterator first = numbers.begin() + 0;
            vector<int>::const_iterator last = numbers.begin() + 25;
            vector<int> oneToTwentyFive(first, last);


        }

        if (input == 'n')
        {
            // [26, 50]
            vector<int>::const_iterator first = numbers.begin() + 25;
            vector<int>::const_iterator last = numbers.begin() + 50;
            vector<int> twentySixToFifty(first, last);

        }
    }
    if (input == 'n')
    {

    }
}