/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef MYLABEL_H
#define MYLABEL_H

#include <cstring>
#include <vector>

class MyLabel
{
public:
	void Labeling(const char *binary);
	void Init(const int iw, const int ih);

	long& operator() (const int x, const int y);
	const long& operator() (const int x, const int y) const;

private:
	std::vector<long> m_label;

public:
	int w, h;
	long num;
};


#endif