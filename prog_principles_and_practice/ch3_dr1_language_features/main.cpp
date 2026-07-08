#include "../PPPheaders.h"

int main()
{
    string value1, value2;
    while(cin >> value1 && value1 != "|"
          && cin >> value2 && value2 != "|") {
        cout << value1 << " " << value2 << '\n';
    }

    return 0;
}
