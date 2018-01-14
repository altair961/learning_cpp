// ch4_words_bleeping.cpp : Defines the entry point for the console application.
// This program takes in words from the keyboard and then shows them with
// prohibited words bleeped out.
	
#include "stdafx.h"
#include "../std_lib_facilities.h"

void bleep_out(vector<string>, string, vector<string>);

int main()
{
	vector<string> words;
	vector<string> disliked = { "broccoli", "Broccoli", "storm", "computer" };

	string bleep_sign = "BLEEP";
	cout << "Please, input words" << endl;

	for (string temp; cin >> temp && temp!= "|";)
		words.push_back(temp);

	bleep_out(words, bleep_sign, disliked);
	keep_window_open();
}

void bleep_out(vector<string> words, string bleep_sign, vector<string> disliked)
{
	for (int i = 0; i < words.size(); i++)
		for (int j = 0; j < disliked.size(); j++)
			if (words[i] == disliked[j])
				words[i] = bleep_sign;

	for (string word : words)
		cout << word << endl;
}
