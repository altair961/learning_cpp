/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#include "mymat.h"

MyMat::MyMat():m_data(NULL)
{
}

MyMat::MyMat(const int rows, const int cols, const int type):m_data(NULL)
{
	Init(rows, cols, type);
}

MyMat::MyMat(const MyMat &src):m_data(NULL)
{
	Clone(src);
}

MyMat::~MyMat()
{
	Release();
}

void MyMat::Mul(const MyMat& src1, const MyMat& src2)
{
	cvMatMul(src1.m_data, src2.m_data, m_data);
}

void MyMat::Homography(const MyMat& src, const MyMat& dst, const double repro)
{
	cvFindHomography(src.m_data, dst.m_data, m_data, CV_RANSAC, repro);
}

void MyMat::Clone(const MyMat &src)
{
	Release();
	m_data = cvCloneMat(src.m_data);
}

void MyMat::Release()
{
	if(m_data != NULL){
		cvReleaseMat(&m_data);
		m_data = NULL;
	}
}

void MyMat::Clean()
{
	cvSetZero(m_data);
}

void MyMat::Init(const int rows, const int cols, const int type)
{
	m_data =cvCreateMat(rows, cols, type);
	Clean();
}

double& MyMat::operator() (const int row, const int col)
{
	return m_data->data.db[col+row*m_data->cols];
}

const double& MyMat::operator() (const int row, const int col) const
{
	return m_data->data.db[col+row*m_data->cols];
}