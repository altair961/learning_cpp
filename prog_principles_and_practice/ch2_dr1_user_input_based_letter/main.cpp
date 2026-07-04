#include "../PPPheaders.h"

using namespace std;

string first_name = "";
string friend_name = "";
int age = -1;

int main()
{
    cout << "Enter the name of the person you want to write to: ";
    cin >> first_name;
    cout << "Enter the name of the friend: ";
    cin >> friend_name;
    cout << "Enter the age of the person you want to write to: ";
    cin >> age;

    cout << "\nDear " << first_name << ", "
         << "\nHow are you? I am fine. I have heard, you have finished you project. Congratulations! "
         << "\nHave you seen " << friend_name << " lately? "
         << "\nI hear you just had a birthday and you are " << age << " years old.\n";

    if((age < 0 ) || (age > 100))
    {
        error("you're kidding!");
    } else if (age < 12) {
        cout << "Next year you will be " << age+1 << ".";
    } else if (age == 17) {
        cout << "Next year you will be able to vote.";
    } else if (age > 70) {
        cout << "Are you retired?";
    }

    cout << "\n\nYours sincerely\n\n\n" << "Nicolas";

    return 0;
}
