#pragma once

#include <string>

class Tank 
{
private:
	std::string name;
public:
	Tank(std::string n);
	~Tank();
	std::string GetName() const { return name; }
	//int pixels[2];

};