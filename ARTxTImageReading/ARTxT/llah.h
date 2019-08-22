/*
	This file is part of ARTxT, a software for augmented reality on text.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef LLAH_H
#define LLAH_H

#include <vector>

#include "mylib/myimage.h"
#include "mylib/mymat.h"
#include "mylib/mylabel.h"
#include "llahparam.h"
#include "bloblist.h"
#include "hashtable.h"
#include "paperlist.h"
#include "paper.h"

typedef std::vector<Paper*> visible;

class LLAH
{
public:

	void ClearPaper();
	void DeletePaper();
	void SetHash(Paper* paper, const eblobs *blobs);
	void AddPaper(const MyImage &src);

	visible* GetVisiblePaper();
	bool FindPaper(const int min=10, const double repro=5.0);

	double ComputeAffine(const blob *target, const combi &nm, const combi &mk) const;
	unsigned ComputeIndex(const blob *target, const combi &nm) const;
	void ComputeDescriptors(blob *target);
	void Retrieve();

	void CoordinateTransform(const double h, const double ratio);
	void SetPts();
	void Extract(const MyImage &src);
	void Init(const int iw, const int ih);

	void DrawBinary(MyImage &dst) const;
	void DrawPts(MyImage &dst) const;

private:
	MyImage m_gray;
	MyImage m_blur;
	MyImage m_binary;
	MyLabel m_label;
	LLAHParam m_param;
	BlobList m_bloblist;
	HashTable m_table;
	PaperList m_paperlist;
	visible m_visible;
};

#endif