#ifndef LIB_ROTARYENCODER
#define LIB_ROTARYENCODER
#include <stdio.h>

#define ROTARY_PORTA 21
#define ROTARY_PORTB 22

static const int dir[] = { 0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0 }; /* 回転方向テーブル */
static int indexTableDirection;                           /* インデックス */
static int position;
static int dataCurrentA,dataCurrentB;

int getPosition(void);
#endif
