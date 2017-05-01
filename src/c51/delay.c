/*********************************************************************
 *
 *                          delay.c
 *
 *********************************************************************
 * File Name  : delay.c
 * Description: define delay functions
 * Version    : V1.0
 * Date       : 2017-04-02 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#include "../../include/c51/delay.h"

void delayOneMs() {
#if SDCC
	uint8 i = 166 / MC_US;
	for(; i > 0; i --);

#endif

#if KEIL
	uint8 i = 250;
	while(i--);
	i = 250;
	while(i--);
#endif
}

void delayMs(uint8 ms) {
	do {
		delayOneMs();
	}while(ms--);
}

/**************************** End of file ***************************/
