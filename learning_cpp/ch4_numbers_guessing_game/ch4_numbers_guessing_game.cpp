// ch4_numbers_guessing_game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../std_lib_facilities.h"

int determine_number(int, int);

int users_number = 0;

string answer;
int half = 0;

int main()
{
	users_number = determine_number(0, 100);
	cout << "users_number: " << users_number << endl;
	keep_window_open();
}

int determine_number(int left_edge, int right_edge)
{
	int result = 0;

	cout << "State before actions:" << endl;
	cout << "right_edge: " << right_edge << endl;
	cout << "left_edge: " << left_edge << endl;
	cout << "users_number: " << users_number << endl;
	half = left_edge + (ceill((right_edge - left_edge) / 2.0));
	cout << "half: " << half << endl;
	cout << "less than " << half << "?" << endl;
	cin >> answer;
	if (answer == "y")
	{
		right_edge = half;
		result = determine_number(left_edge, right_edge);
		return result;
	}
	if (answer == "n")
	{
		cout << "greater than " << half << "?" << endl;
		cin >> answer;
		if (answer == "y")
		{
			left_edge = half;
			result = determine_number(left_edge, right_edge);
		}
		else
		{
			result = half;
			return result;
		}
	}
	return result;
}