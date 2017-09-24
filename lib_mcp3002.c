#include "lib_mcp3002.h"

//Mcp3002によりデジタル変換された温度データを表示します
void dispStatusTemp(int chan,char* output)
{
  double adValue,voltage,resistance,temp;
   
  adValue=gertboardAnalogRead (0);
  //printf("\nadValue= %f ",adValue);
  voltage=adValue/1024.0*3.3;
  //printf("voltage=%f ",voltage);

  resistance=(3300.0-1000.0*voltage)/voltage;
  //printf("resistance=%f ",resistance);
     
  temp=1.0/(1.0/(273+25)+(1.0/3100.0)*log(resistance/1000.0));
  //printf("temp(K)=%f",temp);
  //printf("temp(C)=%f\n",temp-273);
  sprintf(output,"adValue=%f voltage=%f resistance=%f \ntemp(K)=%f temp(C)=%f",adValue,voltage,resistance,temp,temp-273);
  
}

//Mcp3002により取得された温度を返します
double getTemperature(int chan)
{
  double adValue,voltage,resistance,temp;

  adValue=gertboardAnalogRead (0);
  voltage=adValue/1024.0*3.3;

  resistance=(3300.0-1000.0*voltage)/voltage;
     
  temp=1.0/(1.0/(273+25)+(1.0/3100.0)*log(resistance/1000.0));
  return temp-273;

}

void gertboardAnalogWrite (int chan, int value)
{
  unsigned char spiData [2] ;
  unsigned char chanBits, dataBits ;
 
  if (chan == 0)
    chanBits = 0x30 ;
  else
    chanBits = 0xB0 ;
 
  chanBits |= ((value >> 4) & 0x0F) ;
  dataBits  = ((value << 4) & 0xF0) ;

  spiData [0] = chanBits ;
  spiData [1] = dataBits ;
 
  wiringPiSPIDataRW (SPI_D2A, spiData, 2) ;
}

int gertboardAnalogRead (int chan)
{
   uint8_t spiData [2] ;
 
   uint8_t chanBits ;
 
    if (chan == 0)
      chanBits = 0b11010000 ;
    else
      chanBits = 0b11110000 ;
  
    spiData [0] = chanBits ;
    spiData [1] = 0 ;
  
    wiringPiSPIDataRW (SPI_A2D, spiData, 2) ;
  
    return ((spiData [0] << 7) | (spiData [1] >> 1)) & 0x3FF ;
}
 
