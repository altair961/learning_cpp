#include "../PPPheaders.h"

int square(int number) {

    int result = 0;

    for(int i = 0; i < number; ++i){
        result += number;
    }

    return result;
}

int main()
{
    for(int i = 0; i < 100; ++i) {
        cout << i << '\t' << square(i) << '\n';
    }

    return 0;
}

