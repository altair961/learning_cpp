#include "../std_lib_facilities.h"

int main()
{
	cout << "Please, specify words, separated by spaces.\n"
		<< "Press Ctrl+Z (on Windows) or Ctrl+D (on Linux)\n"
		<< "followed by Enter when you are done: ";

	vector<string> words;
	for (string inputStr; cin >> inputStr;)
		words.push_back(inputStr);

	string disliked = "Broccoli";

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == disliked)
		{
			words[i] = "BLEEP";
		}
	}

	for (string word : words)
	{
		cout << word << " ";
	}
}