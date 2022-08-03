#pragma once

#include <string>
#include <vector>
#include <memory>
#include "PixelEngine.h"

using std::string;

class Tank
{
private:
	string name;
public:
	std::unique_ptr<PixelEngine> pPixelEngine;
	Tank(string n);
	~Tank();
	string GetName() const { return name; };
};