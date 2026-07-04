// GuessMyNumberGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


auto answer = 7.0;
double guess = 0.0;

int main()
{
	cout << "Please, enter your guess about a number, I think of.";

	do 
	{
		cin >> guess;
		if (guess < answer) cout << "That's too high!" << endl;
		if (guess > answer) cout << "That's too low!" << endl;
		if (guess == answer) cout << "Just right!!!" << endl;
	} while (guess != answer);

    return 0;
}

