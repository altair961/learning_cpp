#include <iostream>
#include "Person.h"
using std::string;

int Dummy(Person p) { return p.GetNumber(); }

int main()
{
    {
        Person Kate("Kate", "Gregory", 345);
        Kate.AddResource();
        string s1 = Kate.GetResource();
        Kate.AddResource();

        // bad things that won't cause us problems anymore
        Person Kate2 = Kate;
        Kate = Kate2;
        int j = Dummy(Kate2);
    }
}