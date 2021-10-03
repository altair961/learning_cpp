#pragma once
#include "TanksGameAppInterfaces.h" 

class Adder : IAdd
{
public:
    int balanse = 5;
    int Add(int, int);
};
