#include "Tank.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

Tank::Tank(string n) :name(n)
{
	cout << "constructing " << name << endl;
}

Tank::~Tank()
{
	cout << "distructing " << name << endl;
}
