#include "../PPPheaders.h"

int main() {
    cout << "Please enter your first name and age in years\n";
    string first_name = "???";
    double age = -1;
    cin >> first_name >> age;
    cout << "Hello " << first_name << " (age " << age * 12 << ")\n";
}