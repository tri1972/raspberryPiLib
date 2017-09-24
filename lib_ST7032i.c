#include "lib_ST7032i.h"

void LCD_init(int fd)
{
  delay(40);
  // Function Set。8bit bus mode, 2-line mode,normal font,normal instruction mode。
  LCD_write(LCD_RS_CMD, 0b00111000, fd);
  // Function Set。extension instruction modeへ。
  LCD_write(LCD_RS_CMD, 0b00111001, fd);
  // Internal OSC frequency(extension instruction mode)設定。
  LCD_write(LCD_RS_CMD, 0b00010100, fd);
  // Contrast set(extension instruction mode)。コントラスト値下位4bit設定。
  LCD_write(LCD_RS_CMD, 0b01110000 | (LCD_CONTRAST & 0xF), fd);
  // Power/ICON/Contrast set(extension instruction mode)。
  // アイコン On,booster On,コントラスト値上位2bit設定。
  LCD_write(LCD_RS_CMD, 0b01011100 | ((LCD_CONTRAST >> 4) & 0x3), fd);
  // Follower control。internal follower on, 
  LCD_write(LCD_RS_CMD, 0b01101100, fd);
  // 時間待ち。
  delay(300);
    
  // Function Set。normal instruction mode。
  LCD_write(LCD_RS_CMD, 0b00111000, fd);
  // Display On/Off。Display Onに設定。
  LCD_write(LCD_RS_CMD, 0b00001100, fd);
  // Clear Display。
  LCD_write(LCD_RS_CMD, 0b00001100, fd);
  // 時間待ち。
  delay(2);
}

void LCD_write(unsigned char rs, unsigned char data, int fd)
{
  unsigned char buf[2];
 
  if (rs == LCD_RS_CMD || rs == LCD_RS_DATA)
    {
      // LCD_RS_CMD ならコマンドモード。LCD_RS_DATA ならデータモード。
        
      buf[0] = rs;
      buf[1] = data;
      delay(10);
      if (write(fd, buf, 2) != 2)
	{
	  printf("Error writeing to i2c slave1\n");
	}        
    }
  else
    {
      // rsの指定がLCD_RS_CMD,LCD_RS_DATA以外ならなにもしない。
    }
}

void LCD_clear(int fd)
{
  LCD_write(LCD_RS_CMD, LCD_CMD_CLEAR, fd);
  delay(2);
  LCD_write(LCD_RS_CMD, LCD_CMD_HOME, fd);
  delay(2);
}

void LCD_setCursor(unsigned char col, unsigned char row, int fd)
{
  unsigned char offset[] = {0x00, 0x40};
    
  if (row > 1)    row = 1;
  if (col > 16)    col = 16;
    
  LCD_write(LCD_RS_CMD, 0x80 | (col + offset[row]), fd);
}

void LCD_putc(unsigned char c, int fd)
{
  LCD_write(LCD_RS_DATA, c, fd);
}

void LCD_puts(char *str, int fd)
{
  int i;
  for (i = 0; i < 16; i++)
    {
      if (str[i] == 0x00)
        {
	  break;
        }
      else
        {
	  LCD_putc((unsigned int)str[i], fd);
        }
    }
}
