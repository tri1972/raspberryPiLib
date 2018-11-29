#include "lib_buttonWithLamp.h"

void initButton(void){

  pinMode(BOARD_SW3, INPUT);
  pinMode(BOARD_SW4, INPUT);
  pinMode(BOARD_SW5, INPUT);

  pinMode(LIGHTSW3, OUTPUT);
  pinMode(LIGHTSW4, OUTPUT);
  pinMode(LIGHTSW5, OUTPUT);
  isOnSw5=true;
}

void getOnOffSwitch5(void){
      if(digitalRead(BOARD_SW5)==1){
	isOnSw5=true;
	digitalWrite(LIGHTSW5,1);
      }else{
	isOnSw5=false;
	digitalWrite(LIGHTSW5,0);
      }

      //チャタリング防止のため少し待つ
  delay(50);//20ms待ち

}

