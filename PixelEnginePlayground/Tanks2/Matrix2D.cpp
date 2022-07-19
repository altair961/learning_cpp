#include "Matrix2D.h"
#include <iostream>

using namespace std;

Matrix2D::Matrix2D(string n) : name(n)
{
	cout << "constructing " << name << endl;
}

Matrix2D::~Matrix2D()
{
	cout << "distructing " << name << endl;
}