/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifdef _OPENMP
#include <omp.h>
#endif

#include <cstdlib>
#include <GL/glut.h>
#include <GL/gl.h>
const GLsizei NUMTEXTURE = 2;
GLuint m_texture[NUMTEXTURE];

#include <iostream>

#include "mylib/glwindow.h"
GLWindow m_window;

#include "mylib/mymat.h"
#include "mylib/mycam.h"
MyCam m_cam;

#include "mylib/myimage.h"
MyImage m_camimg;
MyImage m_nextcamimg;
MyImage m_img;
MyImage m_nextimg;

const double m_ratio = 0.5;

#include "llah.h"
LLAH m_llah;

#include "mylib\mytimer.h"

//added
#include "FilesFilter.h"

void setview(const MyMat& src, GLdouble *dst);
void drawCG();
void drawimg();
void getimg();
void showimg();
void update();

void mainloop();

void terminator();

void display();
void displaysize();
void stopdisplay();
void adddeletepaper();
void clearpaper();
void keyboard(unsigned char key, int x, int y);
void idle();
void reshape(const int w, const int h);

void showmode();
void trackingInit();
void camInit();
void glInit();

bool m_binarymode = false;
bool m_stopmode = false;
bool m_viewmode = false;
bool m_ptmode = false;

//added
void imgInit(const char *imgpath);
IplImage* resizeImg(IplImage* img, float maxDimension = 1024);
void nextImg();

MyImage m_currentImg;
MyImage m_displayedImg;

std::vector<std::string> imagePaths;
int currentImgIndex;
