// ch4_digit_parsing_mini_calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../std_lib_facilities.h"


int spelled_out_to_number(string);
int get_item_index(vector<string>, string);
bool is_word(string);
bool is_number(string);
int get_digit_val(string);

char operator_sign;
string operation_name = "";
double result = 0.0;
//vector<string> spelled_out_digits{ "zero", "one", "two",
//									"three", "four", "five",
//									"six", "seven", "eight", "nine" };
string spelled_out_result = "";

int main()
{
	cout << "Please enter digits for calculation. To finish the input type \"|\": " 
		 << endl;
	
	vector<string> inputs;
	string input = "";
	auto operands_amount = 0;
	while (cin >> input && input != "|")
	{
		inputs.push_back(input);
		operands_amount++;
	}
	
	cout << "Now type-in a character representing an operation: "
		 << endl;
	cin >> operator_sign;
	
	vector<int> operands(operands_amount);

	for (auto i = 0; i < inputs.size(); i++)
	{
		if (is_word(inputs.at(i))) operands.at(i) = get_digit_val(inputs.at(i));
		if (is_number(inputs.at(i))) operands.at(i) = inputs.at(i).at(0) - '0';
	}

	//for (int operand : operands)
	//{
	//	if (is_word(input)) operand = get_digit_val(input);
	//	if (is_number(input)) operand = input.at(0) - '0';
	//}
	
//	for (operand : opernads) {
		/*if (is_word(operand)) {
			numeric_result = spelled_out_to_number(operand);
		}
		if (is_number(input)) {
			spelled_out_result = spelled_out_digits[input.at(0) - '0'];
		}*/
//	}
	
	
	/*
	// here we sh create a vector of the size == inputs.size
	vector<int> operands;
	for (string input : inputs) 
	{
		operands.push_back(0);
	}
	// end of vector creating 

	*/


	//	if (is_word(input)) {
	//		// first_operand = spelled_out_to_number(input);
	//	}
	//	if (is_number(input)) {
	//		spelled_out_result = spelled_out_digits[input.at(0) - '0'];
	//		cout << spelled_out_result << endl << endl;
	//	}
	//	else {
	//		cout << endl << "Please, provide a number or a word representing the number!" << endl << endl;
	//	}	
	////}
	
	switch (operator_sign)
	{
	case '+':
		result = operands[0] + operands[1];
		operation_name = "sum";
		break;
	case '-':
		result = operands.at(0) + operands.at(1);
		operation_name = "subtraction";
		break;
	case '*':
		result = operands.at(0) + operands.at(1);
		operation_name = "multiplication";
		break;
	case '/':
		result = operands.at(0) + operands.at(1);
		operation_name = "division";
		break;
	default:
		cout << "Unknown operator, please provide +, -, * or /" << endl;
		break;
	}

	cout << "The " << operation_name << " of "
		<< operands[0] << " and "
		<< operands[1] << " is "
		<< result << endl;

	keep_window_open();
	return 0;
}

//int spelled_out_to_number(string word) {
//	
//	vector<string> spelled_out_digits{ "zero", "one", "two",
//		"three", "four", "five",
//		"six", "seven", "eight", "nine" };
//
//	int result = -1;
//
//	for (string spelled_out_digit : spelled_out_digits) {
//		if (spelled_out_digit == word) {
//			result = get_item_index(spelled_out_digits, word);
//			cout << result << endl << endl;
//		}
//	}
//
//	return result;
//}

int get_item_index(vector<string> words, string word)
{
	auto result = -1;

	for (int i = 0; i < words.size(); i++)
		if (words.at(i) == word) result = i;
	
	return result;
}

bool is_word(string input) {
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

bool is_number(string input) {
	bool result = false;
	int constexpr number_0 = 48;
	int constexpr number_9 = 57;

	if (input.at(0) >= number_0 && input.at(0) <= number_9)
		result = true;
	else
		result = false;

	return result;
}

int get_digit_val(string word)
{
	vector<string> spelled_out_digits{ "zero", "one", "two",
		"three", "four", "five",
		"six", "seven", "eight", "nine" };

	auto result = -1;

	for (string spelled_out_digit : spelled_out_digits)
		if (spelled_out_digit == word) result = get_item_index(spelled_out_digits, word);

	return result;
}