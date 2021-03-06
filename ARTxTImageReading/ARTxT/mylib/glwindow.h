/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef GLWINDOW_H
#define GLWINDOW_H

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glut.h>

const int MAXSIZE = 1024;

class GLWindow
{
public:

	void Draw(const char* data);
	void SetTexture(const int texturenum);
	void Init(const int iw, const int ih, const char* name);


private:
	GLuint m_texture;
	int m_ID;
	double m_wr, m_hr;
	int m_w, m_h;
};



#endif