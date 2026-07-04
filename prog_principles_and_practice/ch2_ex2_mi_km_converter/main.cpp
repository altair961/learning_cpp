#include "../PPPheaders.h"

double mi = 0.0;
double ratio = 1.609;

int main()
{
    cout << "Miles to kilometers converter. \n"
         << "Enter miles: ";
    cin >> mi;
    cout << mi << " mi == " << mi * ratio << " km.";
}
