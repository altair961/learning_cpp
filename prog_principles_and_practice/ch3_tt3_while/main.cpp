#include "../PPPheaders.h"

int main()
{
    int i = 97;
    while(i <= 122)
    {
        cout << char(i) << '\t' << i << "\n";
        ++i;
    }

    return 0;
}
