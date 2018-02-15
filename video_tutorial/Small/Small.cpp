// Small.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


double add(double x, double y) 
{
	return x + y;
}

int main()
{
	auto a = add(3, 4);
	cout << "3 + 4 is " << a << endl;

	auto b = add(1.2, 3.4);
	cout << "1.2 + 3.4 is " << b << endl;

	return 0;
}

