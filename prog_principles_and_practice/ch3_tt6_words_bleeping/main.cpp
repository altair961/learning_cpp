#include "../PPPheaders.h"

bool isDisliked(const string& word, vector<string>& disliked){
    for(string disliked_word : disliked) {
        if(word == disliked_word) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<string> disliked = {"Broccoli", "Canal"};
    string word = "";
    while(cin >> word) {
        if(isDisliked(word, disliked))
            cout << "BLEEP" << endl;
        else
            cout << word << endl;
    }

    return 0;
}
