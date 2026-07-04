#ifndef person_h
#define person_h
#include <string>

using namespace std;

class Person {
    private:
        string name;

    public:
        Person(string theName);
        string getName();
};
#endif