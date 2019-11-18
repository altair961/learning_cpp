// This progarm bleeps the disliked words. 
// It writes BLEEP instead of the disliked word

#include "../std_lib_facilities.h"

string to_tower_case(string s);
bool is_forbidden(string word, vector<string> forbidden_words);

int main()
{
	vector<string> forbidden_words = { "broccoli", "museum", "galaxy" };
	cout << "Words from bleep list will be substituted with 'BLEEP'" << endl << endl
	 << "The bleeped words are: ";

	for (string forbidden_word : forbidden_words)
		cout << forbidden_word << " ";

		cout << endl  << endl << "Please enter words separated by space/entrer/tab and press Ctrl+Z followed by enter to finish input: " << endl;

	vector<string> words;

	for (string temp; cin >> temp;)
		words.push_back(to_tower_case(temp));

	for (int i = 0; i < words.size(); i++)
	{
		if (!is_forbidden(words[i], forbidden_words))
			cout << words[i] << " ";
		else
			cout << "BLEEP ";
	}

	cout << endl << endl;
}

string to_tower_case(string s)
{
	string result = "";
	for (char ch : s)
		result += tolower(ch);

	return s;
}

bool is_forbidden(string word, vector<string> forbidden_words) 
{
	for (string forbidden_word : forbidden_words)
		if (word == forbidden_word) return true;
	
	return false;
}