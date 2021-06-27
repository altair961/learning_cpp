#include "../std_lib_facilities.h"

int main() {
	double kilometers {0};
	double kilometersInMile {1.609};
	double miles {0};

	cout << "Please enter kilometers: \n";
	cin >> kilometers;
	miles = kilometers / kilometersInMile;
	cout << "There are " << miles << "miles to the " << kilometers << " kilometers." << "\n";

	return 0;
}

