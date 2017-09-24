#ifndef _ST7032I
#define _ST7032I


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <wiringPi.h>



#define LCD_ADDRESS (0b0111110)
#define LCD_CONTRAST 100

#define LCD_RS_CMD (0x00)
#define LCD_RS_DATA (0x40)
#define LCD_CMD_CLEAR (0x01)
#define LCD_CMD_HOME (0x03)

#endif


// 関数プロトタイプ宣言。
void LCD_init(int fd);
void LCD_write(unsigned char rs, unsigned char data, int fd);
void LCD_clear(int fd);
void LCD_setCursor(unsigned char col, unsigned char row, int fd);
void LCD_putc(unsigned char c, int fd);
void LCD_puts(char *str, int fd);
