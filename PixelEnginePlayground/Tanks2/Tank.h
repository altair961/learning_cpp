#pragma once

#include <string>
#include "Matrix2D.h"
#include <vector>
#include <memory>


class Tank 
{
private:
	string name;
public:
	Tank(string n);
	~Tank();
	//string GetName() const { return name; };
	std::shared_ptr<std::vector<int>> PTankPicture;
	void AddResource();
};