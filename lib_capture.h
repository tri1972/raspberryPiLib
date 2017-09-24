#ifndef _CAPTURE
#define _CAPTURE

// OpenCV カメラ画像取得テスト。
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>

#include <opencv/highgui.h>
#include <opencv/cv.h>

//キャプチャー画面解像度
#define  CAP_WIDTH 800
#define CAP_HEIGHT 600
/*
#define  CAP_WIDTH 160
#define CAP_HEIGHT 120

#define  CAP_WIDTH 320
#define CAP_HEIGHT 240

#define  CAP_WIDTH 640
#define CAP_HEIGHT 460
*/

//保存画像回転角度
#define ROTATE_DEGREE 180

#endif

//プロトタイプ宣言
CvCapture * initCap();
void saveCap(CvCapture *capture,char *fileStr);

