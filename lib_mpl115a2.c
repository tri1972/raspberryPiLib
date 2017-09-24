//mpl115a2用ライブラリ
#include "lib_mpl115a2.h"

//pres:ファイルディスクリプタ
//bufPresData:12byte長の計測データバッファ
void readMPL115A2(int pres, unsigned char bufPresData[])
{
  unsigned char bufPresCmd[2];
  //unsigned char bufPresData[12];


    bufPresCmd[0]=(0x12);
    bufPresCmd[1]=(0x01);
    if(write(pres,bufPresCmd,2)!=2){
      printf("Error writing to i2cCmd_StartConversions\n");

    }
    delay(3);
    bufPresCmd[0]=(0x00);
    if(write(pres,bufPresCmd,1)!=1){
      printf("Error writing to i2cCmd_DeviceAddress+Write bit\n");
    }
    if(read(pres,bufPresData,12)!=12){
      printf("Error reading to i2c\n");
    }
}
//fp:ファイルディスクリプタ
double calcPressure(int fp)
{
  int i;
  int maxNum=20;     //繰り返し計算数
  double a0;
  double b1;
  double b2;
  double c12;
  double Temp;
  double Pressure;

  unsigned char bufPresData[12];
  double Avg;
  double ret;
  for(i=0;i<maxNum;i++){
    
    readMPL115A2(fp,bufPresData);
  /*
    printf("%x %x %x %x %x %x %x %x %x %x %x %x\n",(int)bufPresData[0],(int)bufPresData[1],bufPresData[2],bufPresData[3],bufPresData[4],bufPresData[5],bufPresData[6],bufPresData[7],bufPresData[8],bufPresData[9],bufPresData[10],bufPresData[11]);
  */
    Pressure=((bufPresData[0] * 256 ) + bufPresData[1]) / 64 ;
    Temp=((bufPresData[2] * 256 ) + bufPresData[3]) / 64 ;
    a0=(bufPresData[4]<<5) + (bufPresData[5]>>3)+(bufPresData[5] & (0x07))/8.0;
    b1=((((bufPresData[6] & 0x1F) * 0x100 ) + bufPresData[7]) / 8192.0 ) - 3 ;
    b2=((((bufPresData[8] - 0x80) << 8 ) + bufPresData[9]) / 16384.0 ) - 2 ;
    c12=(((bufPresData[10] * 0x100 ) + bufPresData[11]) / 16777216.0 );

    double f = a0 + ( b1 + c12 * Temp ) * Pressure + b2 * Temp ;
    double calcResult = f * ( 650.0 / 1023.0 ) + 500.0 ;
    Avg+=calcResult;
  }
  printf("Pressure=%f Temp=%f a0=%f b1=%f b2=%f c12=%f\n",Pressure,Temp,a0,b1,b2,c12);
  ret=Avg/maxNum;
    //printf("Pressure(hPa)=%f\n",ret);
    /*
    double h ;
    double Difference=80;// 自宅でのセンサと実際の高度差補正値(My自宅の標高は100m)
    h = 44330.8 * (1.0 - pow( (ret/1013.25) ,  0.190263 )) ;
    h = h + Difference ;
    printf("height=%f\n",h);
    */
    return ret;
}
