#ifndef LIB_MCP3002
#define LIB_MCP3002

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define channel 0
#define errno 0
#define SPI_D2A 0
#define SPI_A2D 0

void gertboardAnalogWrite (int, int);
int gertboardAnalogRead (int);
double getTemperature(int);
void dispStatusTemp(int,char*);

#endif
