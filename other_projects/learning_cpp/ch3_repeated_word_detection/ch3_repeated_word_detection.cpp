// ch3_repeated_word_detection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\std_lib_facilities.h"


int main() {
	string previous = "";
	string current;

	cout << "Please entaer a word, then press enter, then type another word then press enter again and so on, when you type same word twice one after other program reacts to it." << endl;
	cout << "To finish the input type |" << endl;
	while (cin >> current && current != "|") {
		if (previous == current)
			cout << "Repeated word: " + current << '\n';

		previous = current;
	}
	keep_window_open();
}
