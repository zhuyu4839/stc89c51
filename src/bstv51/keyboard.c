/*********************************************************************
 *
 *                          keyboard.c
 *
 *********************************************************************
 * File Name  : key.c
 * Description: key-press c file
 * Version    : V1.0
 * Date       : 2017-04-08
 * Author     : blockish (blockish@yeah.net)
*********************************************************************/
#include "../../include/bstv51/keyboard.h"
#include "../../include/c51/delay.h"

uint8 getKeyCode() {
	uint8 keyCode = 0;
#ifdef MATRIX_KEY
	uint8 tmp;
#endif
//	KEY = 0xFF;
#if defined STAND_ALONE_KEY
	if(!KEY1) {
		delayMs(10);
		if(!KEY1)
			keyCode = K1;
	} else if(!KEY2) {
		delayMs(10);
		if(!KEY2)
			keyCode = K2;
	} else if(!KEY3) {
		delayMs(10);
		if(!KEY3)
			keyCode = K3;
	} else if(!KEY4) {
		delayMs(10);
		if(!KEY4)
			keyCode = K4;
	}
	return keyCode;

#elif defined MATRIX_KEY
	KEY = 0xef;
	tmp = KEY;
	tmp = tmp & 0x0f;
	if(0x0f != tmp) {
		delayMs(10);
		tmp = KEY;
		tmp = tmp & 0x0f;
		if(0x0f != tmp) {
			tmp = KEY;
			LED1 = 0;
			switch(tmp) {
				case 0xee: keyCode = S01;
				break;

				case 0xed: keyCode = S05;
				break;

				case 0xeb: keyCode = S09;
				break;

				case 0xe7: keyCode = S13;
				break;
					
			}
		}
	}
	
	KEY = 0xdf;
	tmp = KEY;
	tmp = tmp & 0x0f;
	if(0x0f != tmp) {
		delayMs(10);
		tmp = KEY;
		tmp = tmp & 0x0f;
		if(0x0f != tmp) {
			tmp = KEY;
			LED2 = 0;
			switch(tmp) {
				case 0xde: keyCode = S02;
				break;

				case 0xdd: keyCode = S06;
				break;

				case 0xdb: keyCode = S10;
				break;

				case 0xd7: keyCode = S14;
				break;
					
			}
		}
	}
	
	KEY = 0xbf;
	tmp = KEY;
	tmp = tmp & 0x0f;
	if(0x0f != tmp) {
		delayMs(10);
		tmp = KEY;
		tmp = tmp & 0x0f;
		if(0x0f != tmp) {
			tmp = KEY;
			LED3 = 0;
			switch(tmp) {
				case 0xbe: keyCode = S03;
				break;

				case 0xbd: keyCode = S07;
				break;

				case 0xbb: keyCode = S11;
				break;

				case 0xb7: keyCode = S15;
				break;
					
			}
		}
	}
	
	KEY = 0x7f;
	tmp = KEY;
	tmp = tmp & 0x0f;
	if(0x0f != tmp) {
		delayMs(10);
		tmp = KEY;
		tmp = tmp & 0x0f;
		if(0x0f != tmp) {
			tmp = KEY;
			LED4 = 0;
			switch(tmp) {
				case 0x7e: keyCode = S04;
				break;

				case 0x7d: keyCode = S08;
				break;

				case 0x7b: keyCode = S12;
				break;

				case 0x77: keyCode = S16;
				break;
					
			}
		}
	}
	return keyCode;
#else
	return keyCode;
#endif
}


/**************************** End of file ***************************/
