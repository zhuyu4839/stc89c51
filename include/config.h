/*********************************************************************
 *
 *                          config.h
 *
 *********************************************************************
 * 文件名: config.h
 * 描  述: 配置头文件
 *
 *************************  宏定义含义  ********************************
 *  ** 宏 **		*** 含义 ***			*** 值 ***
 * SDCC			SDCC编译器			编译器自动定义
 * KEIL			KEIL编译器				0/1
 * MCU51/MCU52		51单片机/52单片机				0/1
 * SEG_CC/SEG_CA	共阴/共阳数码管				无
 * DELAY		使用延时函数				无
 * STAND_ALONE_KEY	使用独立键盘				无
 * MATRIX_KEY		使用矩阵键盘				无
 * WITH_CURSOR		LCD1602显示光标				无
 * WITH_CURSOR_FLASH	LCD1602显示光标且光标闪烁			无
 * WITH_AUTO_INC	LCD1602读写一个字节地址和光标自动加1，	无
 * 			默认自动减1
 * SCREEN_MOVE		LCD1602屏幕自动左右移动，默认不移动		无
 * WITH_TIME0_ISR	使用定时器T0中断				无
 * WITH_TIME1_ISR	使用定时器T1中断				无
 * WITH_TIME2_ISR	使用定时器T2中断(仅52单片机)		无
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *********************************************************************/
#ifndef MAIN_H
#define MAIN_H

/* 使用STC89C51 */
#define MCU52	1

/* 7段共阴数码管 */
#define SEG_CC	1

//#define STAND_ALONE_KEY
#define MATRIX_KEY


#ifndef DELAY
 #define DELAY
#endif

#define WITH_CURSOR
//#define WITH_CURSOR_FLASH
#define WITH_AUTO_INC

#include "./bstv51/bstv51.h"



#endif
