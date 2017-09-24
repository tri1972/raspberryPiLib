#ifndef LIB_BME280
#define LIB_BME280
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>


#define BME280_ADDRESS 0x76
unsigned long int hum_raw,temp_raw,pres_raw;
signed long int t_fine;

unsigned int dig_T1;
int dig_T2;
int dig_T3;
unsigned int dig_P1;
int dig_P2;
int dig_P3;
int dig_P4;
int dig_P5;
int dig_P6;
int dig_P7;
int dig_P8;
int dig_P9;
char  dig_H1;
int dig_H2;
char  dig_H3;
int dig_H4;
int dig_H5;
char  dig_H6;

static int dev;

void readData();
signed long int calibration_T(signed long int adc_T);
unsigned long int calibration_P(signed long int adc_P);
unsigned long int calibration_H(signed long int adc_H);
int init_dev(void);

#endif
