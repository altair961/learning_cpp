///*
//This file is part of ARTxT, a software for Augmented Reality on TeXT.
//Copyright (c) 2011 Hideaki Uchiyama
//
//You can use, copy, modify and re-distribute this software
//for non-profit purposes.
//*/
//
//#include "main.h"
//
//static IplImage* LOADED_IMAGE;
//
//void setview(const MyMat& src, GLdouble *dst)
//{
//	dst[0] = src(0, 0);
//	dst[1] = src(1, 0);
//	dst[2] = 0.0f;
//	dst[3] = src(2, 0);
//
//	dst[4] = src(0, 1);
//	dst[5] = src(1, 1);
//	dst[6] = 0.0f;
//	dst[7] = src(2, 1);
//
//	dst[8] = 0.0f;
//	dst[9] = 0.0f;
//	dst[10] = 1.0f;
//	dst[11] = 0.0f;
//
//	dst[12] = src(0, 2);
//	dst[13] = src(1, 2);
//	dst[14] = 0.0f;
//	dst[15] = src(2, 2);
//}
//
//
//void drawCG()
//{
//	visible *papers = m_llah.GetVisiblePaper();
//
//	for (visible::iterator itpa = (*papers).begin();itpa != (*papers).end();++itpa) {
//
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		glOrtho(0, LOADED_IMAGE->width, 0, LOADED_IMAGE->height, -1, 1);
//
//		GLdouble m[16];
//		setview((*itpa)->h, m);
//
//		glMultMatrixd(m);
//
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//
//		glPushMatrix();
//
//		glColor3d((*itpa)->r, (*itpa)->g, (*itpa)->b);
//
//		glLineWidth(10);
//
//		glBegin(GL_LINE_LOOP);
//		glVertex3f(0.0f, 0.0f, 0.0f);
//		glVertex3f(640.0f, 0.0f, 0.0f);
//		glVertex3f(640.0f, 480.0f, 0.0f);
//		glVertex3f(0.0f, 480.0f, 0.0f);
//		glVertex3f(0.0f, 0.0f, 0.0f);
//		glVertex3f(640.0f, 0.0f, 0.0f);
//		glVertex3f(0.0f, 480.0f, 0.0f);
//		glVertex3f(640.0f, 480.0f, 0.0f);
//		glEnd();
//
//		glPopMatrix();
//	}
//}
//
//void drawimg()
//{
//	m_window.Draw(m_camimg);
//}
//
//void getimg()
//{
//	try
//	{
//		cvCopyImage(LOADED_IMAGE, (IplImage*)m_camimg);
//	}
//	catch (cv::Exception & e)
//	{
//		std::cerr << e.msg << std::endl; // output exception message
//	}
//
//	m_nextimg.Resize(m_nextcamimg);
//}
//
//void showimg()
//{
//	if (m_binarymode) {
//		m_llah.DrawBinary(m_camimg);
//	}
//	if (m_ptmode) {
//		m_llah.DrawPts(m_camimg);
//	}
//
//	drawimg();
//
//	if (m_viewmode) {
//		drawCG();
//	}
//
//	update();
//}
//
//void update()
//{
//	glutSwapBuffers();
//	glFlush();
//}
//
//void mainloop()
//{
//	MyTimer::Push("Time");
//
//	m_llah.SetPts();
//	m_llah.CoordinateTransform(static_cast<double>(LOADED_IMAGE->height), m_ratio);
//
//	showimg();
//
//	m_img.Swap(m_nextimg);
//	m_camimg.Swap(m_nextcamimg);
//
//#ifdef _OPENMP
//#pragma omp parallel
//	{
//#pragma omp master
//		{
//
//			m_llah.Retrieve();
//			m_viewmode = m_llah.FindPaper();
//
//		}
//#pragma omp single
//		{
//			getimg();
//			m_llah.Extract(m_nextimg);
//		}
//	}
//#else
//	m_llah.Retrieve();
//	m_viewmode = m_llah.FindPaper();
//	getimg();
//	m_llah.Extract(m_nextimg);
//#endif
//	MyTimer::Pop();
//}
//
//void terminator()
//{
//	glDeleteTextures(NUMTEXTURE, m_texture);
//	exit(1);
//}
//
//void display()
//{
//	mainloop();
//}
//
//
//void displaysize()
//{
//	static bool full = false;
//
//	if (full) {
//		glutPositionWindow(100, 100);
//		glutReshapeWindow(LOADED_IMAGE->width, LOADED_IMAGE->height);
//	}
//	else {
//		glutFullScreen();
//	}
//
//	full = !full;
//}
//
//void stopdisplay()
//{
//	if (m_stopmode) {
//		glutDisplayFunc(display);
//	}
//	else {
//		glutDisplayFunc(showimg);
//	}
//	m_stopmode = !m_stopmode;
//}
//
//void adddeletepaper()
//{
//	if (!m_binarymode && !m_viewmode) {
//		m_llah.AddPaper(m_camimg);
//	}
//	else if (!m_binarymode && m_viewmode) {
//		m_llah.DeletePaper();
//		m_viewmode = false;
//	}
//}
//
//void clearpaper()
//{
//	if (!m_binarymode) {
//		m_llah.ClearPaper();
//	}
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case 0x1b:
//		terminator();
//		break;
//	case 'a':
//		displaysize();
//		break;
//	case 's':
//		m_binarymode = !m_binarymode;
//		break;
//	case 'd':
//		m_ptmode = !m_ptmode;
//		break;
//	case 'f':
//#pragma omp barrier
//		adddeletepaper();
//		break;
//	case 'c':
//		clearpaper();
//		break;
//	case 'z':
//		stopdisplay();
//		break;
//	default:
//		break;
//	}
//}
//
//void showmode()
//{
//	std::cout << "ESC: exit" << std::endl;
//	std::cout << "  a: full screen" << std::endl;
//	std::cout << "  s: show binary" << std::endl;
//	std::cout << "  d: show pts" << std::endl;
//	std::cout << "  f: add and delete" << std::endl;
//	std::cout << "  c: clear" << std::endl;
//	std::cout << "  z: stop" << std::endl;
//}
//
//void idle()
//{
//	glutPostRedisplay();
//}
//
//void reshape(const int w, const int h)
//{
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void trackingInit()
//{
//	m_llah.Init(m_img.w, m_img.h);
//	showmode();
//}
//
//void glInit()
//{
//	m_window.Init(LOADED_IMAGE->width, LOADED_IMAGE->height, "ARTxT");
//
//	glutReshapeFunc(reshape);
//	glutIdleFunc(idle);
//	glutKeyboardFunc(keyboard);
//	glutDisplayFunc(display);
//
//	glGenTextures(NUMTEXTURE, m_texture);
//	m_window.SetTexture(m_texture[0]);
//
//
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//}
//
//void camInit()
//{
//	if (!m_cam.Init()) {
//		exit(1);
//	}
//
//	m_camimg.Init(m_cam.w, m_cam.h);
//	m_nextcamimg.Init(m_cam.w, m_cam.h);
//
//	m_img.Init(m_cam.w*m_ratio, m_cam.h*m_ratio);
//	m_nextimg.Init(m_cam.w*m_ratio, m_cam.h*m_ratio);
//}
//
//void imgInit()
//{
//	const char* imgpath = "C:/git/Debug/img/38.jpg ";
//	LOADED_IMAGE = cvLoadImage(imgpath, CV_LOAD_IMAGE_COLOR);
//
//	m_camimg.Init(LOADED_IMAGE->width, LOADED_IMAGE->height);
//	m_nextcamimg.Init(LOADED_IMAGE->width, LOADED_IMAGE->height);
//
//	m_img.Init(LOADED_IMAGE->width*m_ratio, LOADED_IMAGE->height*m_ratio);
//	m_nextimg.Init(LOADED_IMAGE->width*m_ratio, LOADED_IMAGE->height*m_ratio);
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//
//	// camInit();
//	imgInit();
//	glInit();
//	trackingInit();
//
//	glutMainLoop();
//
//	return 0;
//}
