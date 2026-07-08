#include "../PPPheaders.h"

int main()
{
    int value1, value2;
    while(cin >> value1 && value1 != '|'
          && cin >> value2 && value2 != '|') {

        if(value1 > value2) {
            cout << "The smaller number is: " << value2 << '\n'
            << "and the larger number is: " << value1;
        } else {
            cout << "The smaller number is: " << value1 << '\n'
            << "and the larger number is: " << value2;
        }
    }


    return 0;
}
