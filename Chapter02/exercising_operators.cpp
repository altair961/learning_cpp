#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter an integer value: ";
	int n;
	cin >> n;
	cout << "n == " << n
		 << "\nn+1 == " << n+1
		 << "\nthree times n == " << 3*n
		 << "\ntwice n == " << n+n
		 << "\nn squared == " << n*n
		 << "\ninteger division of n by 2 == " << n/2
		 << "\nreminder of n devided to 2 == " << n%2
		 << "\nsquare root of n == " << sqrt(n)
		 << "\na/b * b + a%b == a: " << n/2 * 2 + n%2 
		 << '\n';
}
