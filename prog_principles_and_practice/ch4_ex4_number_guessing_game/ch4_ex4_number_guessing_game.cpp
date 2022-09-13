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

vector<int> GetCompositeNumSubvector(vector<int> numbers)
{
    vector<int> compositeNums;
    for (int number : numbers)
    {
        vector<int>::const_iterator first = numbers.begin() + 0;
        vector<int>::const_iterator last = numbers.begin() + number;
        vector<int> oneToNumber(first, last);

        if (number == 1)
            continue;

        if (number == 2)
            continue;

        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int denominator = numbers.at(i);
            
            if (denominator >= number)
                continue;

            if (denominator == 1)
                continue;

            int remainder = number % denominator;
            
            if (remainder == 0)
            {
                compositeNums.push_back(number);
                break;
            }
        }
    }
    return compositeNums;
}

vector<int> GetPrimeNumSubvector()//(vector<int> numbers)
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    vector<int> primeNums;

    for (int number : numbers)
    {
        vector<int>::const_iterator first = numbers.begin() + 0;
        vector<int>::const_iterator last = numbers.begin() + number;
        vector<int> oneToNumber(first, last);

        if (number == 1)
            continue;

        if (number == 2)
        {
            primeNums.push_back(number);
            continue;
        }

        vector<int> currentNumberDivisors;
        
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int divisor = numbers.at(i);

            if (divisor > number)
                continue;

            if (divisor == 1)
                continue;

            int remainder = number % divisor;

            if (remainder == 0)
            {
                currentNumberDivisors.push_back(divisor);
            }

            if (currentNumberDivisors.size() == 0)
            {
                primeNums.push_back(number);
                break;
            }

        }
    }
    return primeNums;
}

vector<int> GetPrimeNumSubvector2()//(vector<int> numbers)
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

    vector<int> primeNums;


    for (int number : numbers)
    {
        vector<int>::const_iterator first = numbers.begin() + 0;
        vector<int>::const_iterator last = numbers.begin() + number;
        vector<int> oneToNumber(first, last);

        if (number == 1)
            continue;

        if (number == 2)
        {
            primeNums.push_back(number);
            continue;
        }

        for (int divisor : oneToNumber) // 2 3 4 5 6 7 8 9
        {
            if (divisor == 1)
                continue;

            int remainder = number % divisor;

            if (remainder == 0)
                break;

            if (divisor == number - 1)
                primeNums.push_back(number);

            if (divisor == number)
                break;
        }
    }
    return primeNums;
}

int main()
{
    GetPrimeNumSubvector2();
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

            cout << "Is the number you are thinking of less than 15? ";
            input = GetUsersInput();
            if (input == 'y') 
            {
                vector<int>::const_iterator first = numbers.begin() + 0;
                vector<int>::const_iterator last = numbers.begin() + 14;
                vector<int> oneToFourteen(first, last);

                cout << "Is the number you are thinking of composite? ";
                input = GetUsersInput();

                if (input == 'y')
                {
                    vector<int> oneToFourteenComposite;
                    oneToFourteenComposite = GetCompositeNumSubvector(oneToFourteen);
                }

                if (input == 'n')
                {
                    vector<int> oneToFourteenPrime;
                //    oneToFourteenPrime = GetPrimeNumSubvector(oneToFourteen);
                }
            }
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