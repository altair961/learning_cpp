/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#ifndef OPENCVPATH_H
#define OPENCVPATH_H


#include "opencv/cv.h"
#include "opencv/highgui.h"

#ifdef _DEBUG
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_calib3d2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_contrib2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_core2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_features2d2413d.lib")
//#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_ffmpeg2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_flann2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_gpu2413d.lib")
//#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_haartraining_engine.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_highgui2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_imgproc2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_legacy2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_ml2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_objdetect2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_ts2413d.lib")
#pragma comment(lib, "C:/libs/opencv2.4.13.6/build/x86/vc14/lib/opencv_video2413d.lib")
#pragma comment(lib, "C:/libs/freeglut-MSVC-3.0.0-2.mp/freeglut/lib/freeglut.lib")

#else
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_calib3d2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_contrib2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_core2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_features2d2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_ffmpeg2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_flann2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_gpu2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_haartraining_engine.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_highgui2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_imgproc2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_legacy2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_ml2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_objdetect2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_ts2413.lib")
#pragma comment(lib, "C:/OpenCV/build/lib/Release/opencv_video2413.lib")	
#endif


#endif