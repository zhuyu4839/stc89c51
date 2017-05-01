/*********************************************************************
 *
 *                          segment.c
 *
 *********************************************************************
 * File Name  : segment.h
 * Description: 7 segmeng nixie light display with chip 74HC573
 *              c language file
 * Version    : V1.0
 * Date       : 2017-03-31 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#include "../../include/display/segment.h"
#include "../../include/c51/delay.h"


void singleDisplay(const uint8 duan, const uint8 wei) {

	LE_A = 1;
	SEG = seg[duan];
	LE_A = 0;
#if SEG_CC
	SEG = 0xFF;
#elif SEG_CA
	SEG = 0x00;
#endif

	LE_C = 1;
	SEG = local[wei];
	LE_C = 0;
#if SEG_CC
	SEG = 0x00;
#elif SEG_CA
	SEG = 0xFF;
#endif
}

void segDisplay(const uint8 * info) {

	uint8 i;
	for (i = 0; i < 8; i ++) {

		singleDisplay(*info++, i);
#ifdef DELAY
		delayOneMs();
#endif
	}
}

/*************************** End of file ****************************/
