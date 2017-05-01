/*********************************************************************
 *
 *                          segment.h
 *
 *********************************************************************
 * File Name  : segment.h
 * Description: 7 segmeng nixie light display with chip 74HC573 
 *              head file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#ifndef BLOCKISH_SEGMENT_H
#define BLOCKISH_SEGMENT_H

#include "./../config.h"

/* segment code 0-F */
uint8 CODE seg[] = {
/* cathode/kathode common */
#if SEG_CC
 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x40 
/* anode common */
#elif SEG_CA
 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e, 0xbf 
#endif
};

uint8 CODE local[] = {
#if SEG_CC
 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f 
#elif SEG_CA
 0x01 << 7, 0x01 << 6, 0x01 << 5, 0x01 << 4, 0x01 << 3, 0x01 << 2, 0x01 << 1, 0x01 
#endif
};

extern void singleDisplay(const uint8 duan, const uint8 wei);

/********************************************************************
 * Function Name: segDisplay(const uint8 * info);
 * Discription  : 数码管8位(动态扫描）静态显示,从最高位开始到最低位显示
 * Attention    : 必须要保证数据足够8位,否则造成溢出
 ********************************************************************/
extern void segDisplay(const uint8 * info);

/********************************************************************
 * Function Name: nPgDisplay(const uint8 * info);
 * Discription  : 数码管8位(动态扫描）多页显示
 * Attention    : 
 ********************************************************************/
//extern void nPgDisplay(const uint8 * info, const uint8 num);

#endif
/*************************** End of file ****************************/
