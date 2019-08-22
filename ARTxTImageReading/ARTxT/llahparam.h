/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef LLAHPARAM_H
#define LLAHPARAM_H

#include <cmath>
#include <vector>

#include "mylib/combination.h"

struct LLAHParam
{
	LLAHParam();

	unsigned Quantization(double val) const;

	int n;
	int m;
	int k;
	int stepbit;
	int hashbit;

	unsigned hashsize;

	std::vector<double> step;

	Combination nm;
	Combination mk; 
};

#endif