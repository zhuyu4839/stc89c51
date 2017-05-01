/*********************************************************************
 *
 *                          lcd1602.c
 *
 *********************************************************************
 * File Name  : lcd1602.c
 * Description: LCD1602 display c language file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#include "../../include/display/lcd1602.h"
#include "../../include/c51/delay.h"

uint8 lcdCheckBusy() {

	LCD1602_IO = 0xFF;
	LCD1602_RS = LOW;
	LCD1602_RW = HIGH;
	LCD1602_CE = LOW;
	LCD1602_CE = HIGH;
	
	return (LCD1602_IO & 0x80);
}

void lcdInputCmd(const uint8 cmd) {
	while(lcdCheckBusy());
	LCD1602_RS = LOW;
	LCD1602_RW = LOW;
	LCD1602_CE = HIGH;
	LCD1602_IO = cmd;
	LCD1602_CE = LOW;
}

void __lcdInputData(const uint8 dat) {
	while(lcdCheckBusy());
	LCD1602_RS = HIGH;
	LCD1602_RW = LOW;
	LCD1602_CE = HIGH;
	LCD1602_IO = dat;
	LCD1602_CE = LOW;
}

void lcdInputChar(const uint8 x, const uint8 y, const uint8 ch) {
	if(0 == y)
		lcdInputCmd(ADDR_LINE1 + x);
	else
		lcdInputCmd(ADDR_LINE2 + x);
	__lcdInputData(ch);
}

void lcdInputString(const uint8 x, const uint8 y, const uint8 * str) {
	if(0 == y)
		lcdInputCmd(ADDR_LINE1 + x);
	else 
		lcdInputCmd(ADDR_LINE2 + x);
	do {
		__lcdInputData(*str ++);
	}while(*str);
}

void lcdInit() {

	lcdInputCmd(LCD_MODE);
//	delayMs(5);
	lcdInputCmd(DISPLAY_OFF);
	lcdInputCmd(CLEAR);
	lcdInputCmd(
		AUTO_DEC
#ifdef WITH_AUTO_INC
		| AUTO_INC
#endif
#ifdef WITH_SCREEN_MOVE
		| SCREEN_MOVE
#endif
	);
	lcdInputCmd(
		DISPLAY_ON
#ifdef WITH_CURSOR
		| CURSOR_ON
#endif
#ifdef WITH_CURSOR_FLASH
		| CURSOR_ON | CURSOR_FLASH
#endif
	);
	
}

/**************************** End of file ***************************/
