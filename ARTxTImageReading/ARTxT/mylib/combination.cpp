/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#include "combination.h"

void Combination::Init(const int n, const int m)
{
	int k[200];
	int nest = 0;
	int column = 1;

	Nest(nest, column, m, n-m, k, m_data);
}

allcombi::iterator Combination::begin()
{
	return m_data.begin();
}

allcombi::iterator Combination::end()
{
	return m_data.end();
}

allcombi::const_iterator Combination::begin() const
{
	return m_data.begin();
}

allcombi::const_iterator Combination::end() const
{
	return m_data.end();
}


void Combination::Nest(int nest, int column, int n1, int n2, int k[], allcombi &result)
{
	for(int i=nest+1; i<=n2+column;i++){
		k[column] = i;

		if(n1 != column){
			Nest(i,column+1,n1,n2,k,result);
		}
		else{
			std::vector<int> tmp;
			for(int j=1;j<=n1;j++){
				tmp.push_back(k[j]-1);
			}
			result.push_back(tmp);
		}
	}
}