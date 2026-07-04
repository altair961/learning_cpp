/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef MYMAT_H
#define MYMAT_H

#include "opencvpath.h"

class MyMat
{
public:
	MyMat();
	MyMat(const int rows, const int cols, const int type=CV_64F);
	MyMat(const MyMat &src);
	~MyMat();

	void Mul(const MyMat& src1, const MyMat& src2);
	void Homography(const MyMat& src, const MyMat& dst, const double repro);
	void Clone(const MyMat &src);
	void Release();
	void Clean();
	void Init(const int rows, const int cols, const int type=CV_64F);

	double& operator() (const int row, const int col);
	const double& operator() (const int row, const int col) const;

private:
	cv::Mat *m_data;
};


#endif