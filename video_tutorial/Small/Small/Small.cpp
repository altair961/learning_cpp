// Small.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "Hello!" << endl << 2 + 2;

	cout << endl << endl;

	auto i = 5;
	cout << i << endl;

	auto j = 4.9;
	cout << j << endl;

	i = j;

    return 0;
}

