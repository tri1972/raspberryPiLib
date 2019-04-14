#ifndef LIB_MOTOR_SERVO
#define LIB_MOTOR_SERVO

#include <wiringPi.h>
#include <wiringPiSPI.h>

#define MAXSERVOVALUE 115
#define MINSERVOVALUE 24

#define PWM_PIN 18 //サーボモータ動作用PWMピン番号(PWMが使えるGPIOピンのみ可)
/*
モータ回転実行
 */
int rotationMotor(double);
int rotationMotorNeg(double);
int rotationMotorPos(double);
int rotationMotorStop();
int rotationMotorSpeedCntr(unsigned int interop);



#endif
