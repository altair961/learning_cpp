/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#include "paperlist.h"

Paper* PaperList::FindPaper(const int paperid)
{
	paperlist::iterator found = m_papers.find(paperid);

	if(found == m_papers.end()){
		return NULL;
	}
	else{
		return &(*found).second;
	}
}

void PaperList::Delete(const int paperid)
{
	paperlist::iterator found = m_papers.find(paperid);

	if(found != m_papers.end()){
		m_papers.erase(found); 
	}
}

unsigned PaperList::Add(const MyImage &img, eblobs *blobs)
{
	static unsigned numpaper = 0;
	numpaper++;

	Paper tmp;
	tmp.img.Clone(img);
	tmp.id = numpaper;

	tmp.r = static_cast<double>(rand())/(static_cast<double>(RAND_MAX)+0.1);
	tmp.g = static_cast<double>(rand())/(static_cast<double>(RAND_MAX)+0.1);
	tmp.b = static_cast<double>(rand())/(static_cast<double>(RAND_MAX)+0.1);

	int num=0;

	for(eblobs::iterator iteb=blobs->begin();iteb!=blobs->end();++iteb){

		(*iteb)->SetID(tmp.id, num);

		pt p;
		p.id = (*iteb)->id;
		p.desc = (*iteb)->descs;
		p.rawx = (*iteb)->rawx;
		p.rawy = (*iteb)->rawy;
		p.x = (*iteb)->x;
		p.y = (*iteb)->y;

		tmp.pts.push_back(p);

		++num;
	}

	m_papers.insert(std::pair<unsigned, Paper>(numpaper, tmp));

	return numpaper;	
}

void PaperList::Clear()
{
	m_papers.clear();
}



