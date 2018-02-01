// ch4_digit_speller.cpp : Defines the entry point for the console application.
// Solution for exercise 4.6
// This program reads-in input from the user and converts typed digits into
// spelled-out numbers. So 5 will be conveted to "five" and vice versa. 

#include "stdafx.h"
#include "../std_lib_facilities.h"
#include <algorithm>


bool isWord(string);
bool isNumber(string);
int get_item_index(vector<string>, string);
string input;
string spelled_out_result;
int numeric_result = -1;

int main()
{
	vector<string> spelled_out_digits{ "zero", "one", "two", 
										"three", "four", "five", 
										"six", "seven", "eight", "nine" };

	cout << "Please, provide a digit or a word representing the digit." << endl <<
		"When a number is provided only the first part of it will be processed." << endl <<
		"So 125 will be treated as 1. Type '|' to finish the input " << endl;

	while (cin >> input && input != "|")
	{		
		if (isWord(input)) {
			for (string s : spelled_out_digits) {
				if (s == input) {
					numeric_result = get_item_index(spelled_out_digits, input);
					cout << numeric_result << endl << endl;
				}
			}
		}
		if (isNumber(input)) {
			string temp = input.substr(0, 1);
			temp = temp.at(0);

			spelled_out_result = spelled_out_digits[input.at(0) - '0'];

			cout << spelled_out_result << endl << endl;
		}
		else {
			cout << endl << "Please, provide a number or a word representing the number!" << endl << endl;
		}
	}

	keep_window_open();
    return 0;
}

int get_item_index(vector<string> words, string word)
{
	int result = -1;

	for (int i = 0; i < words.size(); i++)
	{
		if (words.at(i) == word)
			result = i;
	}
	return result;
}

bool isWord(string input) {
	bool result = false;
	int constexpr small_a = 97;
	int constexpr small_z = 122;
	int constexpr capital_a = 65;
	int constexpr capital_z = 90;

	if ((input.at(0) >= small_a && input.at(0) <= small_z) ||
		(input.at(0) >= capital_a && input.at(0) <= capital_z))
		result = true;
	else
		result = false;

	return result;
}

bool isNumber(string input) {
	bool result = false;
	int constexpr number_0 = 48;
	int constexpr number_9 = 57;

	if (input.at(0) >= number_0 && input.at(0) <= number_9)
		result = true;
	else
		result = false;

	return result;
}