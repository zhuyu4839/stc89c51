/*********************************************************************
 *
 *                          blockish_51.h
 *
 *********************************************************************
 * File Name  : blockish_51.h
 * Description: C51 head file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
*********************************************************************/
#ifndef BLOCKISH_51_H
#define BLOCKISH_51_H

typedef unsigned char uint8;
typedef char int8;
typedef unsigned int uint16;
typedef int int16;
typedef unsigned long uint32;
typedef long int32;
typedef unsigned char * puint8;
typedef char * pint8;
typedef unsigned int * puint16;
typedef int * pint16;

#define	TRUE		1
#define	FALSE		0

#define	ON		1
#define	OFF		0

#define	HIGH		1
#define	LOW		0

//#define	NULL		(void)0

/* if use sdcc, define SDCC = 1. and if used keil define KEIL = 1*/
/* if use mcu51, define MCU51 = 1 or define MCU52 = 1 */
#if (SDCC && MCU51)
#include <8051.h>
#elif (KEIL && MCU51)
#include <reg51.h>
#elif (SDCC && MCU52)
#include <8052.h>
#elif (KEIL && MCU52)
#include <reg52.h>
#endif

#if (KEIL)
sbit	P0_0	=	P0^0;
sbit	P0_1	=	P0^1;
sbit	P0_2	=	P0^2;
sbit	P0_3	=	P0^3;
sbit	P0_4	=	P0^4;
sbit	P0_5	=	P0^5;
sbit	P0_6	=	P0^6;
sbit	P0_7	=	P0^7;

sbit	P1_0	=	P1^0;
sbit	P1_1	=	P1^1;
sbit	P1_2	=	P1^2;
sbit	P1_3	=	P1^3;
sbit	P1_4	=	P1^4;
sbit	P1_5	=	P1^5;
sbit	P1_6	=	P1^6;
sbit	P1_7	=	P1^7;

sbit	P2_0	=	P2^0;
sbit	P2_1	=	P2^1;
sbit	P2_2	=	P2^2;
sbit	P2_3	=	P2^3;
sbit	P2_4	=	P2^4;
sbit	P2_5	=	P2^5;
sbit	P2_6	=	P2^6;
sbit	P2_7	=	P2^7;

sbit	P3_0	=	P3^0;
sbit	P3_1	=	P3^1;
sbit	P3_2	=	P3^2;
sbit	P3_3	=	P3^3;
sbit	P3_4	=	P3^4;
sbit	P3_5	=	P3^5;
sbit	P3_6	=	P3^6;
sbit	P3_7	=	P3^7;
#endif

#if SDCC
#define	CODE		__code
#elif KEIL
#define	CODE		code
#endif

#endif
/*************************** End of file ****************************/
