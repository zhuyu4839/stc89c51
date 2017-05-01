/*********************************************************************
 *
 *                          ds1302.c
 *
 *********************************************************************
 * File Name  : ds1302.c
 * Description: ds1302 clock chip driver
 * Version    : V1.0
 * Date       : 2017-04-19 
 * Author     : blockish (blockish@yeah.net)
 ********************************************************************/
#include "../../include/chips/ds1302.h"

uint8 CODE INIT_TIME[] = {0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00};

void __dec2Time(uint8 * dat, TIME_MODE mode) {

	uint8 i ;
	for (i = 0; i < 8; i++) {
		dat[i] = ((dat[i] / 10) << 4) | (dat[i] % 10) ;
	}
	switch(mode) {
		case (AM):
			dat[2] = dat[2] | 0x80 ; 
			break ;	
		case (PM): 
			dat[2] = dat[2] | (0x80 + 0x10) ; 
			break ;	
		default: 
			break ;	
	}
}

void __time2Dec(uint8 * dat) {

	dat[0] = (((dat[0] & 0x70) >> 4) * 10) + (dat[0] & 0x0F) ;
	dat[1] = ((dat[1] >> 4) * 10) + (dat[1] & 0x0F) ;
	dat[2] = (((dat[2] & 0x70) >> 4) * 10) + (dat[2] & 0x0F) ;
	dat[3] = ((dat[3] >> 4) * 10) + (dat[3] & 0x0F) ;
	dat[4] = ((dat[4] >> 4) * 10) + (dat[4] & 0x0F) ;
	//dat[5] = dat[5] % 10 ;
	dat[6] = ((dat[6] >> 4) * 10) + (dat[6] & 0x0F) ;
}

void __restBus() {
	DS1302_CLK = LOW ;
	DS1302_CE = LOW ;
	DS1302_CE = HIGH ;
}

void __ds1302ByteInput(const uint8 dat) {

	uint8 mask ;
	for (mask = 0x01; 0x00 != mask; mask <<= 1) {
		DS1302_IO = LOW ;
		if (0 != dat & mask) {
			DS1302_IO = HIGH ;
		}
		DS1302_CLK = LOW ;
		DS1302_CLK = HIGH ;
	}
}

const uint8 __ds1302ByteOutput() {

	uint8 mask, temp = 0;
	for (mask = 0x01; 0x00 != mask; mask <<= 1) {
		DS1302_CLK = HIGH ;
		DS1302_CLK = LOW ;
		if (DS1302_IO) {
			temp |= mask ;
		}
	}
	return temp ;
}

void __ds1302SingleInput(DS1302_ADDR addr, const uint8 dat) {

	__restBus() ;
	__ds1302ByteInput((addr << 1) | 0x80) ;
	__ds1302ByteInput(dat) ;
	__restBus() ;
}

uint8 __ds1302SingleOutput(DS1302_ADDR addr) {

	uint8 dat ;
	__restBus() ;
	__ds1302ByteInput((addr << 1) | 0x81) ;
	dat = __ds1302ByteOutput() ;
	__restBus() ;

	return dat ;
}

void ds1302Input(DS1302_ADDR addr, const uint8 value) {

	__ds1302SingleInput(__WRP, PROTECT_CLEAR) ;
	__ds1302SingleInput(addr, value) ;
	__ds1302SingleInput(__WRP, PROTECT_SET) ;
	DS1302_CE = LOW ;
}

void ds1302Output(DS1302_ADDR addr, uint8 *out) {
	*out = __ds1302SingleOutput(addr);
}

void ds1302SetChargerLv(CHARGER_LEVEL level) {

	ds1302Input(__TCR, level) ;
}

void ds1302TimeStop() {

	uint8 temp;
	__ds1302SingleInput(__WRP, PROTECT_CLEAR) ;
	temp = __ds1302SingleOutput(SECOND);
	temp |= 0x80;
	__ds1302SingleInput(SECOND, temp);
	__ds1302SingleInput(__WRP, PROTECT_SET) ;
	DS1302_CE = LOW ;
}

void ds1302Init(CHARGER_LEVEL level) {

	uint8 dat ;
	DS1302_CE = LOW ;
	DS1302_CLK = LOW ;
	__ds1302SingleInput(__WRP, PROTECT_CLEAR) ;
	ds1302SetChargerLv(CHARGER_LEVEL1) ;
	dat = __ds1302SingleOutput(SECOND) ;
	if (0 != (dat & 0x80)) {
		ds1302BurstClockInput(INIT_TIME) ;
	}
	__ds1302SingleInput(__WRP, PROTECT_SET) ;
	DS1302_CE = LOW ;
}

TIME_MODE getTimeMode()  {

	uint8 temp;
	DS1302_CE = HIGH ;
	temp = __ds1302SingleOutput(HOUR) ;
	DS1302_CE = LOW ;
	if (temp & 0x10) {
		return PM ;
	}
	return AM ;
	
}

void ds1302BurstRamOutput(uint8 * dat, uint8 length) {

	uint8 i ;

	__restBus() ;
	__ds1302ByteInput(0xff) ;
	for(i = 0; i < length; i ++) {
		dat[i] = __ds1302ByteOutput();
	}
	__restBus() ;
	DS1302_CE = LOW ;
}

void ds1302BurstRamInput(const uint8 * ramDat, uint8 length) {

	uint8 i ;
	__ds1302SingleInput(__WRP, PROTECT_CLEAR);
	__ds1302ByteInput(0xfe) ;
	for(i = 0; i < length; i ++) {
		__ds1302ByteInput(ramDat[i]) ;
	}
	__ds1302SingleInput(__WRP, PROTECT_SET) ;
	DS1302_CE = LOW ;
}

void ds1302BurstClockOutput(uint8 * out) {

	__ds1302ByteInput(0xbf) ;

	out[0] = __ds1302SingleOutput(SECOND);
	out[1] = __ds1302SingleOutput(MINUTE);
	out[2] = __ds1302SingleOutput(HOUR);
	out[3] = __ds1302SingleOutput(DATE);
	out[4] = __ds1302SingleOutput(MONTH);
	out[5] = __ds1302SingleOutput(DAY);
	out[6] = __ds1302SingleOutput(YEAR);
//	out[7] = __ds1302SingleOutput(__WRP);
	__restBus() ;
	DS1302_CE = LOW ;
	//__time2Dec(out, mode) ;
	__time2Dec(out) ;
	
}

void ds1302BurstClockInput(uint8 * in) {
	
	__dec2Time(in, DEFAULT) ;

	__ds1302SingleInput(__WRP, PROTECT_CLEAR) ;
	
	__ds1302ByteInput(0xbe) ;
	__ds1302ByteInput(in[0]);	//second
	__ds1302ByteInput(in[1]);	//minute
	__ds1302ByteInput(in[2]);	//hour
	__ds1302ByteInput(in[3]);	//date
	__ds1302ByteInput(in[4]);	//month
	__ds1302ByteInput(in[5]);	//day
	__ds1302ByteInput(in[6]);	//year
	__ds1302ByteInput(0x80);	//write|protect register

	__restBus() ;
	DS1302_CE = LOW ;
}
/**************************** End of file ***************************/

