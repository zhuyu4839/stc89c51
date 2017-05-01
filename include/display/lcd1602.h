/*********************************************************************
 *
 *                          lcd1602.h
 *
 *********************************************************************
 * File Name  : lcd1602.h
 * Description: LCD1602 display head file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#ifndef BLOCKISH_LCD1602_H
#define BLOCKISH_LCD1602_H

#include "./../config.h"

#define	LCD_MODE	0x38

#define	ADDR_LINE1	0x80
#define ADDR_LINE2	( ADDR_LINE1 + 0x40 )

#define CLEAR		0x01
#define	ENTER		0x02

#define	DISPLAY_OFF	0x08
#define	DISPLAY_ON	( 0x08 | (1 << 2) )
#define	CURSOR_ON	(1 << 1)
#define CURSOR_FLASH	(1 << 0)

#define	AUTO_DEC	0x04
#define AUTO_INC	(1 << 1)
#define SCREEN_MOVE	(1 << 0)

extern void lcdInputCmd(const uint8 cmd);

extern void lcdInputChar(const uint8 x, const uint8 y, const uint8 ch);

extern void lcdInputString(const uint8 x, const uint8 y, const uint8 *s);

extern void lcdInit();

#endif
/**************************** End of file ***************************/
