#include "./lib_motorServo.h"

volatile unsigned int direction;
volatile unsigned int rotaring;


int rotationMotor(double set_degree){

  int servo_pin=PWM_PIN;
  // Set GPIO18 pin to output mode
  pinMode(servo_pin, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);          // 0Vに指定
  pwmSetRange(1024);      // レンジを0～1024に指定
  pwmSetClock(400);       // 後述

  double move_degf=((MAXSERVOVALUE-MINSERVOVALUE)/180.0)*set_degree+MINSERVOVALUE;
  int move_deg=move_degf;
  printf("value= %d,degree=%f\n",move_deg,move_degf);
  pwmWrite(servo_pin, move_deg);
}

int rotationMotorNeg(double speed){
  int output=-1;
  if(speed >= 0){
    output= rotationMotor(90.0-speed);
  }else{
    output=0;
  }

  return output;
}

int rotationMotorPos(double speed){
  int output=-1;
  if(speed >= 0){
    output= rotationMotor(90.0+speed);
  }else{
    output=0;
  }
  return output;
}

int rotationMotorStop(){
  int output=-1;
  output= rotationMotor(90);
  return output;
}

int rotationMotorSpeedCntr(unsigned int interop){
  int output=-1;
  printf("rotationMotorSpeedCntr speed:%d\n",interop);
  
  rotaring=1;
  while(rotaring!=0){
    printf("go\n");
    /*
    if(direction=0){
      output=rotationMotorNeg();
    }else{
      output=rotationMotorPos();
      }*/
    delay(interop);
    rotationMotorPos(5);
    delay(interop);
    rotationMotorStop(5);
    }
}



