/*********************************************************************
 *
 *                          ds1302.h
 *
 *********************************************************************
 * File Name  : ds1302.h
 * Description: ds1302 clock chip head file
 * Version    : V1.0
 * Date       : 2017-04-19 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#ifndef BLOCKISH_DS1302_H
#define BLOCKISH_DS1302_H

#include "./../config.h"

//#define	AM(x)		(x)
//#define	PM(x)		((x) + 12)

#define	PROTECT_SET	0x80
#define PROTECT_CLEAR	0x00

/* CLOCK BURST Register */
//#define	CLK_BURST	0x1F
/* RAM BURST Register */
//#define	RAM_BURST	0x3F
typedef enum {
	SECOND	=	0x00,
	MINUTE	=	0x01,
	HOUR	=	0x02,
	DATE	=	0x03,
	MONTH	=	0x04,
	DAY	=	0x05,
	YEAR	=	0x06,
/* Write Protect Register */
	__WRP	=	0x07,
/* Trickle Charger Register */
	__TCR	=	0x08

} DS1302_ADDR;
/* CHARGER_LEVEL1 ((VCC - 0.7) / 2)mA 
 * CHARGER_LEVEL2 ((VCC - 0.7) / 4)mA 
 * CHARGER_LEVEL3 ((VCC - 0.7) / 8)mA 
 * CHARGER_LEVEL4 ((VCC - 0.7 * 2) / 2)mA 
 * CHARGER_LEVEL5 ((VCC - 0.7 * 2) / 4)mA 
 * CHARGER_LEVEL6 ((VCC - 0.7 * 2) / 8)mA */
typedef enum {
	CHARGER_LEVEL1	=	0xA5, 
	CHARGER_LEVEL2	=	0xA6, 
	CHARGER_LEVEL3	=	0xA7, 
	CHARGER_LEVEL4	=	0xA9, 
	CHARGER_LEVEL5	=	0xAA, 
	CHARGER_LEVEL6	=	0xAB 
} CHARGER_LEVEL;

typedef enum {
	DEFAULT		=	0,
	AM		=	10,
	PM		=	11
} TIME_MODE;

typedef struct __RTCTIME__ {
	uint8 sec ;
	uint8 min ;
	uint8 hour ;
	uint8 date ;
	uint8 mon ;
	uint8 day ;
	uint8 year ;
} Time;

/* 注意：输入时间value值必须先转换为8421码，输出ram时地址需或上0x40 */
extern void ds1302Input(DS1302_ADDR addr, const uint8 value);
/* 注意：输出时间out值是8421码，，输入ram时地址需或上0x40 */
extern void ds1302Output(DS1302_ADDR addr, uint8 * out);

extern void ds1302TimeStop() ;

extern void ds1302SetChargerLv(CHARGER_LEVEL level) ;

extern void ds1302BurstRamOutput(uint8 * out, uint8 length) ;

extern void ds1302BurstRamInput(const uint8 * in, uint8 length) ;

extern void ds1302Init(CHARGER_LEVEL level) ;

extern TIME_MODE getTimeMode() ;
/* 时间突发模式输入输出均为时间10进制模式数组，格式为{ss, mm, hh, DD, MM, dd, YY} */
extern void ds1302BurstClockOutput(uint8 * out) ;

extern void ds1302BurstClockInput(uint8 * in) ;

#endif
/**************************** End of file ***************************/
