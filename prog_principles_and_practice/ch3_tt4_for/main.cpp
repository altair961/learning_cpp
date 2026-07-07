#include "../PPPheaders.h"

int main()
{
    for(int i = 97; i <= 122; ++i)
        cout << char(i) << '\t' << i << '\n';

    for(int i = 65; i <= 90; ++i)
        cout << char(i) << '\t' << i << '\n';

    for(int i = 48; i <= 57; ++i)
        cout << char(i) << '\t' << i << '\n';

    return 0;
}
