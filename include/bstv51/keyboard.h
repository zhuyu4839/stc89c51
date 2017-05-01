/*********************************************************************
 *
 *                          keyboard.h
 *
 *********************************************************************
 * File Name  : keyboard.h
 * Description: key-press head file
 * Version    : V1.0
 * Date       : 2017-04-08
 * Author     : blockish (blockish@yeah.net)
*********************************************************************/
#ifndef BLOCKISH_KEYBOARD_51_H
#define BLOCKISH_KEYBOARD_51_H
#include "./../config.h"

/***************************** Key Code *****************************/
#define	K1	0x01
#define	K2	0x02
#define	K3	0x03
#define	K4	0x04

#define S01	0x11
#define S02	0x12
#define S03	0x13
#define S04	0x14

#define S05	0x21
#define S06	0x22
#define S07	0x23
#define S08	0x24

#define S09	0x31
#define S10	0x32
#define S11	0x33
#define S12	0x34

#define S13	0x41
#define S14	0x42
#define S15	0x43
#define S16	0x44

extern uint8 getKeyCode();

#endif
/**************************** End of file ***************************/
