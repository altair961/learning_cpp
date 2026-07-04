// ch4_rock_paper_scissors.cpp : Defines the entry point for the console application.
// This program plays game rock paper scissors. For randomness of the computer's moves
// it is required to provide three real numbers before game starts.

#include "stdafx.h"
#include <iostream>
#include "../std_lib_facilities.h"
using namespace std;

int get_rnd_next(double, double, double);
char get_move(vector<char>, int);


int main()
{
	vector<char> moves{ 'r', 'p', 's' };
	double first_val;
	double second_val;
	double third_val;

	cout << "Please, provide any three real numbers for our randomizer: " << endl;
	cin >> first_val;
	cin >> second_val;
	cin >> third_val;

	int rnd_val = get_rnd_next(first_val, second_val, third_val);

	auto usr_move = 'a';
	cout << "Now, please, provide r for rocks, p for paper or s for scissors: " << endl;
	cin >> usr_move;

	auto computer_move = get_move(moves, rnd_val);
	cout << "Computer's move: " << computer_move << endl;
	if (usr_move == computer_move)
	{
		cout << "Nobody have won! Try again" << endl;
	}

	if (usr_move == 'r') {
		if (computer_move == 's') {
			cout << "Rocks crush scissors" << endl;
			cout << "You have won!" << endl;
		}

		if (computer_move == 'p') {
			cout << "Paper covers rocks" << endl;
			cout << "The computer has won!" << endl;
		}
	}
	if (usr_move == 's') {
		if (computer_move == 'r') {
			cout << "Rocks crush scissors" << endl;
			cout << "The computer has won!" << endl;
		}

		if (computer_move == 'p') {
			cout << "Scissors cut paper" << endl;
			cout << "You have won!" << endl;
		}

	}
	if (usr_move == 'p') {
		if (computer_move == 's') {
			cout << "Scissors cut paper" << endl;
			cout << "The computer has won!" << endl;
		}
		if (computer_move == 'r') {
			cout << "Paper covers rock" << endl;
			cout << "You have won!" << endl;
		}
	}


	if (usr_move > computer_move)
		cout << "user wins";

	keep_window_open();

	return 0;
}

int get_rnd_next(double first, double second, double third) {
	double result;

	if (first > second)
		result = first / third + second * third / first * (first / second + third);
	double unassined_value;
	if (third > first)
		result = third / first * (second * third / first * (first / second + third));

	result = second * third / first * (first / second + third);

	return result;
}

char get_move(vector<char> moves, int rnd_val) {
	auto resultsIndex = 0;
	for (auto i = 0; i < rnd_val; i++)
	{
		resultsIndex++;

		if (resultsIndex > 2)
			resultsIndex = 0;
	}
	auto result = moves.at(resultsIndex);
	return result;
}