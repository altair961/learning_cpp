// ch4_print_alphabet.cpp : Defines the entry point for the console application.
// This program prints out the alphabet

#include "stdafx.h"
#include "../std_lib_facilities.h"


char letter;

int main() {
	for (int i = 97; i <= 122; i++) {
		cout << i;
		cout << " ";
		cout << char(i);
		cout << '\n';
	}
	keep_window_open();
}
