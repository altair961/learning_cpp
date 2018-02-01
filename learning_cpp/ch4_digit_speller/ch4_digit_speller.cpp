// ch4_digit_speller.cpp : Defines the entry point for the console application.
//

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

	/*
	char myChar = 'k';
	(int)myChar;
	myChar = 7;
	cout << 1 + myChar;
	*/
	//cout << std::distance(spelled_out_digits[0], spelled_out_digits[5]);

	//int x = std::distance(arr, std::find(arr, arr + 5, 3));
	// input == "1";
	//char a = '4';
	//int ia = a - '0';

	//cout << ia + 6;

	//input = "hi";


	//	cout << spelled_out_digits.at(0)[0] << endl;
	//	cout << spelled_out_digits[char(input.at(0))];
		//spelled_out_digits.at(0)[0];

	//	stoi("0");
	//	input.at(0);
		//cout << int(input.at(0)) << endl;;
		//cout << int(input.at(0)) + 2;

	// cout << typeid((int)input.at(0)).name(); //== "int";
	while (cin >> input && input != "|")
	{
		//cout << input << endl << endl;
		
		if (isWord(input)) {
			for (string s : spelled_out_digits) {
				if (s == input) {
					numeric_result = get_item_index(spelled_out_digits, input);
					cout << numeric_result << endl << endl;
				}
			}
			//if (numeric_result == -1)
				//cout << endl << "Please, provide a word representing a number!" << endl << endl;

		//	numeric_result = -1;
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

		


			//97 - 122  a, 65 - 90 A, 48 - 57 0

		
		
		//string type = typeid(((int)input.at(0))).name();
		////if (type == "int")
		//{
		//}
			
	//	if (typeid(((int)input.at(0))).name() == "string")



				

				//get_index_by_value();



			//	numeric_result = char(input);

				//if (input == spelled_out_digits[char(input)])
				//	numeric_result = 0;
				//if (input == "0")
				//	spelled_out_result = spelled_out_digits[0];


				//if ((char(input) == 0))
					//return 0;
			//	if
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