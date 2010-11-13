/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               hlm8070lw8.h
Created on:         19. Februar 2008, 14:49
Belongs to project: uvXpose 

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc. ,
59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef _HLM8070LW8_H
#define	_HLM8070LW8_H

#ifndef _HAS_CONFIG_
    #include "config.h"
#endif
/* Pin information on HLM8070-LCD
1	GND
2	VDD +5V
3	Kontrast
4	I/OC1
5	R/W
6	ex
7	DB0
8	DB1
9	DB2
10	DB3
11	DB4
12      DB5
13	DB6
14	DB7
15	I/OC2
*/

#ifdef _HAS_CONFIG_
    #include "config.h"
#endif

#ifndef _HLM8070_EXT_PORT_CONFIG_ /*controlled by extern config?*/
///*Definition of datalines*/
//#define HLM8070_DBPORT 	PORTB
//#define HLM8070_DBPIN	PINB
//#define HLM8070_DDDR	DDRB
//#define HLM8070_DATA0 	PB0
//#define HLM8070_DATA1 	PB1
//#define HLM8070_DATA2 	PB2
//#define HLM8070_DATA3 	PB3
//#define HLM8070_DATA4 	PB4
//#define HLM8070_DATA5 	PB5
//#define HLM8070_DATA6 	PB6
//#define HLM8070_DATA7 	PB7
//
///*Definition of control lines*/
//#define HLM8070_CPORT	PORTC
//#define HLM8070_CDDR	DDRC
//#define HLM8070_CE	PC0
//#define HLM8070_CIOC1	PC1
//#define HLM8070_CIOC2	PC2
//#define HLM8070_CRW	PC3
#endif


#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <string.h>




#ifdef	__cplusplus
extern "C" {
#endif


    
/*function set each single bit of DB out*/
void HLM8070_DB(bool bit7,
	bool bit6,
	bool bit5,
	bool bit4,
	bool bit3,
	bool bit2,
	bool bit1,
	bool bit0);

/*set / clear E*/
void HLM8070_E(bool state);


/*set / clear E*/
void HLM8070_RW(bool state);


/*set / clear IOC1*/
void HLM8070_IOC1(bool state);

/*set / clear IOC2*/
void HLM8070_IOC2(bool state);

/*get setting flags from lcd (RB)*/
uint8_t HLM8070_Getflags( void );

/*wait while lcd busy*/
void HLM8070_Wait_Busy( void );

/*set function mode  (SF)*/ 
void HLM8070_Set_Function_Mode(	bool IO,
			bool FONT,
			bool DT1,
			bool DT2,
			bool RA1,
			bool RA2);

/*set entry mode (SE)*/
void HLM8070_Set_Entry_Mode(bool CSRD1,
			bool CSRW,
			bool CSRR,
			bool DSPD1,
			bool DSPW,
			bool DSPR);

/*set display mode (SD)*/
void HLM8070_Set_Display_Mode(	
			bool DSPonoff,
			bool CSRonoff,
			bool UNDonoff,
			bool CSRblink,
			bool CHRblink);
/*move start address (MA)*/
void HLM8070_Move_Start_Address(bool CSR,
			bool CSRD1,
			bool DSP,
			bool DSPD1);

/*set underline mode (SU)*/
void HLM8070_Set_Underline_Mode(bool USRonoff,
			bool UNDSR);

/*write underline bit (WU)*/
void HLM8070_Write_Underline_Inst(bool UNDSR,
				bool CSR1);

/*set blinking frequency (SB)*/
void HLM8070_Set_Blinking_Frequency(bool B1,
				bool B0);

/*set address home (MH)*/
void HLM8070_Dsp_Address_Home( void );

/*clear display and home cursor (CH)*/
void HLM8070_Cldsp_Home( void );

/*do nothing set db clear (NOP)*/
void HLM8070_Nop( void );

/*read cursor address (RC)*/
uint8_t HLM8070_Read_Cursor_Address( void );

/*read display start address (RS)*/
uint8_t HLM8070_Read_Display_Address( void );

/*read ram data instruction(RD)*/
uint8_t HLM8070_Read_Ram_Data( void );

/*write cursor address (WC)*/
void HLM8070_Write_Cursor_Address(uint8_t address);

/*write display start (WS)*/
void HLM8070_Write_Start_Address(uint8_t address);

/*write ram data (WD)*/
void HLM8070_Write_Ram_Data(	bool bit7,
				bool bit6,
				bool bit5,
				bool bit4,
				bool bit3,
				bool bit2,
		 		bool bit1,
				bool bit0);

/*write a single char to current cursor position*/
void HLM8070_Write_Char(unsigned char character);

/*init lcd display*/
void HLM8070_Init( void );

/*write a string beginning at current cursor position*/
void HLM8070_Write_String(char* character);

/*set current cursor position*/
void HLM8070_Cursor_Pos(uint8_t line ,uint8_t column);

/*clear a char on a position on display*/
void HLM8070_Clear_Char(uint8_t line ,uint8_t column);





#ifdef	__cplusplus
}
#endif

#endif	/* _HLM8070LW8_H */

