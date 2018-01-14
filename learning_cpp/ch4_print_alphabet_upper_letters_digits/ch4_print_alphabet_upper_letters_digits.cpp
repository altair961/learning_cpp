// ch4_print_alphabet_upper_letters_digits.cpp : Defines the entry point for the console application.
// This program prints out alphabet in small and upper case 

#include "stdafx.h"
#include "../std_lib_facilities.h"


char letter;

int main()
{
	for (int i = 97; i <= 122; i++)
	{
		cout << i;
		cout << " ";
		cout << char(i);
		cout << '\n';// 97 122
	}

	for (int i = 65; i <= 90; i++)
	{
		cout << i;
		cout << " ";
		cout << char(i);
		cout << '\n';
	}

	for (int i = 48; i <= 57; i++)
	{
		cout << i;
		cout << " ";
		cout << char(i);
		cout << '\n';
	}

	keep_window_open();
}
