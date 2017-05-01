/*********************************************************************
 *
 *                          main.c
 *
 *********************************************************************
 * 文件名: main.c
 * 描  述: 主程序
 ********************************************************************/
//#include "./include/display/segment.h"
//#include "../include/bstv51/keyboard.h"
#include "../include/display/lcd1602.h"
#include "../include/chips/ds1302.h"
#include "../include/c51/delay.h"
/**
 * @brief 
 */
void main() {
	
	//uint8 initTime[] = {58, 35, 12, 24, 04, 01, 17};
	uint8 time[7];

	lcdInit();

		lcdInputChar(0, 0, '2');
		lcdInputChar(1, 0, '0');

		lcdInputChar(4, 0, '-');

		lcdInputChar(7, 0, '-');

		lcdInputChar(11, 0, 'W');
		lcdInputChar(12, 0, 'e');
		lcdInputChar(13, 0, 'e');
		lcdInputChar(14, 0, 'k');

		lcdInputChar(2, 1, ':');

		lcdInputChar(5, 1, ':');

	ds1302Init(CHARGER_LEVEL4);

	//ds1302BurstClockInput(initTime);
	
	while (1) {
/*
		time[0] = ds1302Output(SECOND);
		time[1] = ds1302Output(MINUTE);
		time[2] = ds1302Output(HOUR);
		time[3] = ds1302Output(DATE);
		time[4] = ds1302Output(MONTH);
		time[5] = ds1302Output(DAY);
		time[6] = ds1302Output(YEAR);
*/
		ds1302BurstClockOutput(time) ;

		//lcdInputChar(0, 0, '2');
		//lcdInputChar(1, 0, '0');
		//lcdInputChar(2, 0, ((time[6] & 0x70) >> 4) + '0');
		//lcdInputChar(3, 0, (time[6] & 0x0F) + '0');
		lcdInputChar(2, 0, (time[6] / 10) + '0');
		lcdInputChar(3, 0, (time[6] % 10) + '0');

		//lcdInputChar(4, 0, '-');

		//lcdInputChar(5, 0, ((time[4] & 0x70) >> 4) + '0');
		//lcdInputChar(6, 0, (time[4] & 0x0F) + '0');
		lcdInputChar(5, 0, (time[4] / 10) + '0');
		lcdInputChar(6, 0, (time[4] % 10) + '0');

		//lcdInputChar(7, 0, '-');

		//lcdInputChar(8, 0, ((time[3] & 0x70) >> 4) + '0');
		//lcdInputChar(9, 0, (time[3] & 0x0F) + '0');
		lcdInputChar(8, 0, (time[3] / 10) + '0');
		lcdInputChar(9, 0, (time[3] % 10) + '0');

		//lcdInputChar(11, 0, 'W');
		//lcdInputChar(12, 0, 'e');
		//lcdInputChar(13, 0, 'e');
		//lcdInputChar(14, 0, 'k');
		//lcdInputChar(15, 0, (time[5] & 0x0F) + '0');
		lcdInputChar(15, 0, time[5] + '0');

		//lcdInputChar(0, 1, ((time[2] & 0x70) >> 4) + '0');
		//lcdInputChar(1, 1, (time[2] & 0x0F) + '0');
		lcdInputChar(0, 1, (time[2] / 10) + '0');
		lcdInputChar(1, 1, (time[2] % 10) + '0');

		//lcdInputChar(2, 1, ':');

		//lcdInputChar(3, 1, ((time[1] & 0x70) >> 4) + '0');
		//lcdInputChar(4, 1, (time[1] & 0x0F) + '0');
		lcdInputChar(3, 1, (time[1] / 10) + '0');
		lcdInputChar(4, 1, (time[1] % 10) + '0');

		//lcdInputChar(5, 1, ':');

		//lcdInputChar(6, 1, ((time[0] & 0x70) >> 4) + '0');
		//lcdInputChar(7, 1, (time[0] & 0x0F) + '0');
		lcdInputChar(6, 1, (time[0] / 10) + '0');
		lcdInputChar(7, 1, (time[0] % 10) + '0');

	}
}
