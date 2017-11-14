#include "..\std_lib_facilities.h"

void bleep_out(vector<string>, string, string);

int main()
{
  vector<string> words;
  string disliked = "Broccoli";
  string bleep_sign = "BLEEP";
  cout << "Please, input words" << endl;

  for(string temp; cin >> temp;)
    words.push_back(temp);

  bleep_out(words, bleep_sign, disliked);
}

void bleep_out(vector<string> words, string bleep_sign, string disliked)
{
  for (int i = 0; i < words.size(); i++)
  {
    if(words[i] == disliked)
      words[i] = bleep_sign;
  }

  for(string word : words)
    cout << word << endl;
}
