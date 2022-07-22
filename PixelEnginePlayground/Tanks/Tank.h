#pragma once

#include <string>
#include <vector>
#include <memory>

using std::string;

class Tank 
{
private:
	string name;
public:
	Tank(string n);
	~Tank();
	string GetName() const { return name; };
};