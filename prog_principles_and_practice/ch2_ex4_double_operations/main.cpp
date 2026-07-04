#include "../PPPheaders.h"

double val1 = 0;
double val2 = 0;

int main(){
    cout << "Enter floating-point val1: ";
    cin >> val1;
    cout << "Enter floating-point val2: ";
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
    cout << "Ratio: " << val1 / val2 << '\n';
}
