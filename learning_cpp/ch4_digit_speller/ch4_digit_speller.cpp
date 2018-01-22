// ch4_digit_speller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../std_lib_facilities.h"
#include <algorithm>


int get_item_index(vector<string>, string);
vector<string> spelled_out_digits;
string input;
string spelled_out_result;
int numeric_result;

int main()
{
	spelled_out_digits.push_back("zero");
	spelled_out_digits.push_back("one");
	spelled_out_digits.push_back("two");
	spelled_out_digits.push_back("three");
	spelled_out_digits.push_back("four");
	spelled_out_digits.push_back("five");
	spelled_out_digits.push_back("six");
	spelled_out_digits.push_back("seven");
	spelled_out_digits.push_back("eight");
	spelled_out_digits.push_back("nine");
	/*
	char myChar = 'k';
	(int)myChar;
	myChar = 7;
	cout << 1 + myChar;
	*/
	//cout << std::distance(spelled_out_digits[0], spelled_out_digits[5]);

	//int x = std::distance(arr, std::find(arr, arr + 5, 3));
	// input == "1";
	char a = '4';
	int ia = a - '0';

	cout << ia + 6;

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
		cout << input << endl << endl;
		string type = typeid((int)input.at(0)).name();
		if (type == "int") {
			int temp = (input.at(0));
			spelled_out_result = spelled_out_digits[temp];

			cout << spelled_out_result << endl << endl;
		}
			
		if (typeid((int)input.at(0)).name() == "string")
			for (string s : spelled_out_digits)
				if (s == input) {
					numeric_result = get_item_index(spelled_out_digits, input);
					cout << numeric_result << endl << endl;
				}
				else
					cout << "Please, provide a digit or a word representing the digit." << endl <<
							"When a number is provided only the last part of it will be processed." << endl <<
							"So 125 will be treated as 5" << endl;


				

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
	int result = 0;

	for (int i = 0; i < words.size() - 1; i++)
	{
		if (words.at(i) == word)
			result = i;
	}
	return result;
}

