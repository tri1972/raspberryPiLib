#ifndef LIB_BUTTONWITHLAMP
#define LIB_BUTTONWITHLAMP

#include <stdio.h>
#include <stdbool.h>
#include <wiringPi.h>

#define BOARD_SW5 15
#define BOARD_SW4 16
#define BOARD_SW3 11
#define LIGHTSW5 25
#define LIGHTSW4 28
#define LIGHTSW3 29

//割り込み出力用スイッチオンオフ検出変数
bool isOnSw3;
bool isOnSw4;
bool isOnSw5;

void initButton(void);
void getOnOffSwitch5(void);


#endif
