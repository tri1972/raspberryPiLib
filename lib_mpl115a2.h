#ifndef LIB_MPL115a2
#define LIB_MPL115a2

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

double calcPressure(int fp);
void readMPL115A2(int pres, unsigned char bufPresData[]);

#endif
