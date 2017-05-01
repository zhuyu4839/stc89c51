/*********************************************************************
 *
 *                          bstv51.h
 *
 *********************************************************************
 * File Name  : bstv51.h
 * Description: BST-V51 V3.0 head file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
*********************************************************************/
#ifndef BLOCKISH_BSTV51_H
#define BLOCKISH_BSTV51_H

#include "../c51/blockish_51.h"

#define	FOSC		11059200		/* Crystal Frequency */
#define	FMODE		12			/*  */

#define	MC_US		( (12000000 / FOSC) )	/* Machine Cycle uS */

#define	LED_ON		0
#define	LED_OFF		1

/**************************** LED define *****************************/
#define	LED1		P1_0
#define	LED2		P1_1
#define	LED3		P1_2
#define	LED4		P1_3
#define	LED5		P1_4
#define	LED6		P1_5
#define	LED7		P1_6
#define	LED8		P1_7

/***************************** LCD1602 ******************************/
#define	LCD1602_RS	P1_0
#define	LCD1602_RW	P1_1
#define	LCD1602_CE	P2_5
#define	LCD1602_IO	P0

/**************************** LCD12864 *****************************/
#define	LCD12864_RS	P2_6
#define	LCD12864_RW	P2_5
#define	LCD12864_CE	P2_7

#define	LCD12864_PSB	P3_2
#define	LCD12864_NC1	P3_3
#define	LCD12864_RES	P3_4
#define	LCD12864_IO	P0

/***************************** DS1302 ******************************/
#define	DS1302_IO	P2_0
#define	DS1302_CLK	P2_1
#define	DS1302_CE	P2_4

/************************* DA/AD PCF8591 ***************************/
#define	PCF8591_IO	P2_0
#define	PCF8591_SCL	P2_1

/****************************** Uart *******************************/
#define	UART_TXD	P3_0
#define	UART_RXD	P3_1

/******************************* 24C02 *****************************/
#define	EEP_IO		P2_0
#define	EEP_CLK		P2_1

/******************************* infrare ***************************/
#define	IR_TX		P1_5
#define	IR_RX		P3_2

/******************************* buzzer ****************************/
#define	BUZZ		P2_3

/************************** Temperature 18B20 **********************/
#define	DS1820_DQ	P2_2

/****************************** Keyboard ***************************/
#define	KEY1		P3_4
#define	KEY2		P3_5
#define	KEY3		P3_6
#define	KEY4		P3_7

#define	KEY		P3

/*********************** 7 Segment Nixie light *********************/
#define	LE_A		P2_6	// Segment select
#define	LE_C		P2_7	// bit select
#define	SEG		P0	// segment

/****************************** Bluetooth **************************/
#define	BT_TXD		P3_0
#define	BT_RXD		P3_1

/******************************** WIFI *****************************/
#define	WIFI_RST	P1_0
#define	WIFI_SCK	P1_1
#define	WIFI_MIS	P1_2
#define	WIFI_CE		P1_3
#define	WIFI_MOS	P1_4
#define	WIFI_IRQ	P1_5

#endif
/**************************** End of file ***************************/
