#include "../PPPheaders.h"

int val1 = 0;
int val2 = 0;

int main(){
    cout << "Enter integer val1: ";
    cin >> val1;
    cout << "Enter integer val2: ";
    cin >> val2;

    if(val1 > val2)
    {
        cout << "val1 is greater than val2\n";
    } else if (val1 == val2) {
        cout << "val1 and val2 are equal\n";
    } else {
        cout << "val2 is greater than val1\n";
    }

    cout << "Sum: " << val1 + val2 << '\n';
    cout << "Difference: " << val1 - val2 << '\n';
    cout << "Product: " << val1 * val2 << '\n';
    cout << "Ratio: " << (double)val1 / val2 << '\n';
}
