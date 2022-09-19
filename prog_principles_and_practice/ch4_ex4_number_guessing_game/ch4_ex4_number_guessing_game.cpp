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


vector<int> GetPrimeNumSubvector(vector<int> numbers)
{
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

        for (int divisor : oneToNumber)
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
    vector<int> numbers = GetNums();

    cout << "Please, think of a number between 1 and 100.\n"
        << "Answer the questions with \"y\" for \"yes\" or \"n\" for \"no\".\n\n";

    cout << "Is the number you are thinking of less than 51? ";
    char input = GetUsersInput();

    if (input == 'y') // [1, 50]
    {
        vector<int>::const_iterator first = numbers.begin() + 0;
        vector<int>::const_iterator last = numbers.begin() + 50;
        vector<int> oneToFifty(first, last);

        cout << "Is the number you are thinking of less than 26? ";
        input = GetUsersInput();
        if (input == 'y') // [1, 25]
        {
            vector<int>::const_iterator first = numbers.begin() + 0;
            vector<int>::const_iterator last = numbers.begin() + 25;
            vector<int> oneToTwentyFive(first, last);

            cout << "Is the number you are thinking of less than 15? ";
            input = GetUsersInput();
            if (input == 'y') // [1, 14]
            {
                vector<int>::const_iterator first = numbers.begin() + 0;
                vector<int>::const_iterator last = numbers.begin() + 14;
                vector<int> oneToFourteen(first, last);

                cout << "Is the number you are thinking of composite? ";
                input = GetUsersInput();

                if (input == 'y') // 4 6 8 9 10 12 14
                {
                    vector<int> oneToFourteenComposite;
                    oneToFourteenComposite = GetCompositeNumSubvector(oneToFourteen);

                    cout << "Is the number you are thinking of less than 9? ";

                    input = GetUsersInput();
                    if (input == 'y') // 4 6 8
                    {
                        vector<int> oneToEightComposite;
                        for (int number : oneToFourteenComposite)
                        {
                            if (number < 9)
                                oneToEightComposite.push_back(number);
                        }

                        cout << "Is the number you are thinking of divisible by 3? ";
                        input = GetUsersInput();
                        if (input == 'y') // 6
                        {
                            vector<int> oneToEightCompositeDivisibleByThree;
                            for (int number : oneToEightComposite)
                            {
                                int remainder = number % 3;
                                if (remainder == 0) 
                                {
                                    oneToEightCompositeDivisibleByThree.push_back(number);
                                    int result = oneToEightCompositeDivisibleByThree[0];
                                    cout << "The number you are thinking of is " << result << "\n";
                                }                                
                            }
                        }

                        if (input == 'n') // 4 8
                        {
                            vector<int> oneToEightCompositeNotDivisibleByThree;
                            for (int number : oneToEightComposite)
                            {
                                int remainder = number % 3;

                                if (remainder != 0)
                                    oneToEightCompositeNotDivisibleByThree.push_back(number);
                            }

                            cout << "Is the number you are thinking of less than 5? ";
                            input = GetUsersInput();
                            if (input == 'y') // 4
                            {
                                vector<int> oneToEightCompositeLessThanFive;
                                for (int number : oneToEightCompositeNotDivisibleByThree)
                                {
                                    if (number < 5)
                                    {
                                        oneToEightCompositeLessThanFive.push_back(number);
                                        int result = oneToEightCompositeLessThanFive[0];
                                        cout << "The number you are thinking of is " << result << "\n";
                                    }
                                }
                            }

                            if (input == 'n') // 8
                            {
                                vector<int> oneToEightCompositeNotLessThanFive;
                                for (int number : oneToEightCompositeNotDivisibleByThree)
                                {
                                    if (number >= 5) 
                                    {
                                        oneToEightCompositeNotLessThanFive.push_back(number);
                                        int result = oneToEightCompositeNotLessThanFive[0];
                                        cout << "The number you are thinking of is " << result << "\n";
                                    }
                                }
                            }
                        }
                    }
                }

                if (input == 'n') // 2 3 5 7 11 13
                {
                    vector<int> oneToFourteenPrime;
                    oneToFourteenPrime = GetPrimeNumSubvector(oneToFourteen);
                    
                    cout << "Is the number you are thinking of less than 6? ";
                    input = GetUsersInput();

                    if (input == 'y') // 2 3 5
                    {
                        vector<int> oneToFourteenPrimeLessThanSix;
                        for (int number : oneToFourteenPrime)
                        {
                            if (number < 6)
                                oneToFourteenPrimeLessThanSix.push_back(number);
                        }

                        cout << "Is the number you are thinking of less than 3? ";
                        input = GetUsersInput();

                        if (input == 'y') // 2
                        {
                            vector<int> oneToFourteenPrimeLessThanSixLessThanThree;
                            for (int number : oneToFourteenPrimeLessThanSix)
                            {
                                if (number < 3)
                                    oneToFourteenPrimeLessThanSixLessThanThree.push_back(number);
                            }
                            int result = oneToFourteenPrimeLessThanSixLessThanThree[0];
                            cout << "The number you are thinking of is " << result << "\n";
                        }

                        if (input == 'n') // 3 5
                        {
                            vector<int> oneToFourteenPrimeLessThanSixNotLessThanThree;
                            for (int number : oneToFourteenPrimeLessThanSix)
                            {
                                if (number >= 3)
                                    oneToFourteenPrimeLessThanSixNotLessThanThree.push_back(number);
                            }

                            cout << "Is the number you are thinking of less than 4? ";
                            input = GetUsersInput();

                            if (input == 'y') // 3
                            {
                                vector<int> oneToFourteenPrimeLessThanSixNotLessThanThreeLessThanFour;
                                for (int number : oneToFourteenPrimeLessThanSixNotLessThanThree)
                                {
                                    if (number < 4)
                                        oneToFourteenPrimeLessThanSixNotLessThanThreeLessThanFour.push_back(number);
                                }

                                int result = oneToFourteenPrimeLessThanSixNotLessThanThreeLessThanFour[0];
                                cout << "The number you are thinking of is " << result << "\n";
                            }

                            if (input == 'n') // 5
                            {
                                vector<int> oneToFourteenPrimeLessThanSixNotLessThanThreeNotLessThanFour;
                                for (int number : oneToFourteenPrimeLessThanSixNotLessThanThree)
                                {
                                    if (number >= 4)
                                        oneToFourteenPrimeLessThanSixNotLessThanThreeNotLessThanFour.push_back(number);
                                }

                                int result = oneToFourteenPrimeLessThanSixNotLessThanThreeNotLessThanFour[0];
                                cout << "The number you are thinking of is " << result << "\n";
                            }
                        }
                    }

                    if (input == 'n') // 7 11 13
                    {
                        vector<int> oneToFourteenPrimeNotLessThanSix;
                        for (int number : oneToFourteenPrime)
                        {
                            if (number >= 6)
                                oneToFourteenPrimeNotLessThanSix.push_back(number);
                        }

                        cout << "Is the number you are thinking of less than 10? ";
                        input = GetUsersInput();

                        if (input == 'y') // 7
                        {
                            vector<int> oneToFourteenPrimeNotLessThanSixLessThanTen;
                            for (int number : oneToFourteenPrimeNotLessThanSix)
                            {
                                if (number < 10)
                                    oneToFourteenPrimeNotLessThanSixLessThanTen.push_back(number);
                            }

                            int result = oneToFourteenPrimeNotLessThanSixLessThanTen[0];
                            cout << "The number you are thinking of is " << result;
                        }

                        if (input == 'n') // 11 13
                        {
                            vector<int> oneToFourteenPrimeNotLessThanSixNotLessThanTen;
                            for (int number : oneToFourteenPrimeNotLessThanSix)
                            {
                                if (number >= 10)
                                    oneToFourteenPrimeNotLessThanSixNotLessThanTen.push_back(number);
                            }

                            cout << "Is the number you are thinking of less than 12? ";
                            input = GetUsersInput();

                            if (input == 'y') // 11
                            {
                                vector<int> oneToFourteenPrimeNotLessThanSixNotLessThanTenLessThanTwelve;
                                for (int number : oneToFourteenPrimeNotLessThanSixNotLessThanTen)
                                {
                                    if (number < 12)
                                        oneToFourteenPrimeNotLessThanSixNotLessThanTenLessThanTwelve.push_back(number);
                                }

                                int result = oneToFourteenPrimeNotLessThanSixNotLessThanTenLessThanTwelve[0];
                                cout << "The number you are thinking of is " << result;
                            }

                            if (input == 'n') // 13
                            {
                                vector<int> oneToFourteenPrimeNotLessThanSixNotLessThanTenNotLessThanTwelve;
                                for (int number : oneToFourteenPrimeNotLessThanSixNotLessThanTen)
                                {
                                    if (number >= 12)
                                        oneToFourteenPrimeNotLessThanSixNotLessThanTenNotLessThanTwelve.push_back(number);
                                }

                                int result = oneToFourteenPrimeNotLessThanSixNotLessThanTenNotLessThanTwelve[0];
                                cout << "The number you are thinking of is " << result;
                            }
                        }
                    }
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