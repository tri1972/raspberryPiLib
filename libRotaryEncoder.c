#include "libRotaryEncoder.h"

int getPosition(){
  int n;

  int dataA = digitalRead(ROTARY_PORTA);
  int dataB = digitalRead(ROTARY_PORTB);
  //printf("\rGPIO%d = %d GPIO%d = %d",ROTARY_PORTA,dataA,ROTARY_PORTB,dataB);
 
  if( dataCurrentA!=dataA || dataCurrentB!=dataB){
    //printf("\rGPIO%d = %d GPIO%d = %d",ROTARY_PORTA,dataA,ROTARY_PORTB,dataB);
    indexTableDirection = (indexTableDirection << 2) + ((dataA<<1)+dataB);   /* 前回値と今回値でインデックスとする */
    n = dir[indexTableDirection & 15];                    /* 変化パターンから動きを得る */
    if (n) {                            /* 動きがあったら位置更新 */
      position += n;
    }
    //printf("moved = %d\n",position);
    //printf("GPIO%d = %d\n",ROTARY_PORTA,dataA);
    //printf("GPIO%d = %d\n",ROTARY_PORTB,dataB);
     
    dataCurrentA=dataA;
    dataCurrentB=dataB;


  }
  return position;
}
