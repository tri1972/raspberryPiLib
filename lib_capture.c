#include "lib_capture.h"
/*
int main(int argc, char **argv)
{
  char *fileStr;

  if(argc>1){
    if(strcmp("-h",argv[1])==0){
      printf("-f:キャプチャファイルパス指定\n");
      exit(1);
    }else if(strcmp("-f",argv[1])==0){
      if(argc<3){
	printf("ファイル名が指定されていません\n");
	exit(1);
      }
      fileStr=argv[2];
      printf("指定パス:%s に保存します\n",fileStr);
    }else{
      printf("不明なオプションです\n");
      exit(1);
    }
  }else{
      fileStr="capture.jpg";
      printf("デフォルトファイルパス:%s に保存します\n",fileStr);
  }


  CvCapture *capture = 0;  
  capture=initCap();

  int c;
  int errorCount=0;
  time_t current_time,before_time;//時間計測用構造体
  double sec_time;//時間（秒
  time(&before_time);  

  while(1){  
      time(&current_time);
      sec_time=difftime(current_time,before_time);
      if(sec_time>3.0)
      {
	saveCap(capture,fileStr);
	before_time=current_time;
      }
    //if(c=='\x1b')break;
  }
  printf("errorCount=%d\n",errorCount);
  // 後片付け。
  cvReleaseCapture(&capture);
  return 0;
}
*/
CvCapture *initCap()
{
  CvCapture *capture = 0;
  IplImage *frame = 0;

  
  cvSetErrMode(CV_ErrModeLeaf);

  // カメラに対するキャプチャ構造体を作成。

    capture = cvCreateCameraCapture(-1);

    //printf("かめらキャプチャオブジェクト作成\n");

  // キャプチャサイズの設定。
  cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, CAP_WIDTH);
  cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT,CAP_HEIGHT);
  //printf("画像解像度設定作成\n");
  
//捨てキャプチャ
  frame = cvQueryFrame(capture);
  
  return capture;

}
void saveCap(CvCapture *capture,char *fileStr)
{
  int c;
  IplImage *frame = 0;
  // 出力用画像
  IplImage *imgOut = 0;

  // 画像キャプチャ。
  frame = cvQueryFrame(capture);

  //printf("erromode=%d\n",cvGetErrMode);
    
  //if( cvGetErrStatus() < 0 )
  //  printf("Some error occured\n" );
  //else
  //  printf("Everything is OK\n" );
  c = cvWaitKey(10);

  //画像回転
  // 回転行列
  CvMat* rotationMat;
  // 指定に基づいた画像ヘッダ、及びそのデータ領域を生成する
  imgOut = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
  // 回転行列領域の確保
  rotationMat = cvCreateMat(2 ,3 ,CV_32FC1);

  // 180度の回転行列を求める
  cv2DRotationMatrix(cvPoint2D32f(frame->width / 2,frame->height / 2), ROTATE_DEGREE, 1, rotationMat);
  //cv2DRotationMatrix(cvPoint2D32f(frame->height / 2, frame->width / 2), 180, 1, rotationMat);
  // 回転
  cvWarpAffine(frame,imgOut,rotationMat,CV_WARP_FILL_OUTLIERS, cvScalarAll (0));
  //画像保存
  cvSaveImage(fileStr,imgOut,0);
  printf("キャプチャを実行しました\n");

  //cvReleaseImage(&frame);
  //cvReleaseImage(&imgOut);
  // 後片付け。
  //cvReleaseCapture(&capture);
}
