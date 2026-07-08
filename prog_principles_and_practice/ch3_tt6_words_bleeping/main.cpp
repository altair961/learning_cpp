#include "../PPPheaders.h"

int main()
{
    string disliked = "Broccoli";
    vector<string> words;
    for(string temp; cin >> temp;)
        words.push_back(temp);

    for(string word : words)
        if(word == disliked)
            cout << "BLEEP" << endl;
        else {
            cout << word << endl;
        }
    return 0;
}
