/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               hlm8070lw8.c
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


#include "hlm8070lw8.h"

void HLM8070_DB(bool bit7,
	bool bit6,
	bool bit5,
	bool bit4,
	bool bit3,
	bool bit2,
	bool bit1,
	bool bit0)
{	
	HLM8070_DBPORT&=0x00;
	if(bit0){HLM8070_DBPORT|=(1<<HLM8070_DATA0);}
	if(bit1){HLM8070_DBPORT|=(1<<HLM8070_DATA1);}
	if(bit2){HLM8070_DBPORT|=(1<<HLM8070_DATA2);}
	if(bit3){HLM8070_DBPORT|=(1<<HLM8070_DATA3);}
	if(bit4){HLM8070_DBPORT|=(1<<HLM8070_DATA4);}
	if(bit5){HLM8070_DBPORT|=(1<<HLM8070_DATA5);}
	if(bit6){HLM8070_DBPORT|=(1<<HLM8070_DATA6);}
	if(bit7){HLM8070_DBPORT|=(1<<HLM8070_DATA7);}
}


void HLM8070_E(bool state)	{
	if(state)
	{
		_delay_us(1);
		HLM8070_CPORT |=  (1<<HLM8070_CE);
	}
	else
	{
		_delay_us(1);
		HLM8070_CPORT &= ~(1<<HLM8070_CE);
	}
}

void HLM8070_RW(bool state)
{
	if(state)
	{
		/*clear HLM8070_DBPORT*/
		HLM8070_DBPORT=0x00;
		/*set HLM8070_DBPORT as input*/
		HLM8070_DDDR=0x00;
		/*set RW Bit*/
		HLM8070_CPORT |=  (1<<HLM8070_CRW);
	}
	else
	{
		HLM8070_CPORT &= ~(1<<HLM8070_CRW);
		/*set HLM8070_DBPORT as output*/
		HLM8070_DDDR=0xFF;
		
	}
}

void HLM8070_IOC1(bool state)
{
	if(state)
	{
		HLM8070_CPORT |=  (1<<HLM8070_CIOC1);
	}
	else
	{
		HLM8070_CPORT &= ~(1<<HLM8070_CIOC1);
	}
}

void HLM8070_IOC2(bool state)
{
	if(state)
	{
		HLM8070_CPORT |=  (1<<HLM8070_CIOC2);
	}
	else
	{
		HLM8070_CPORT &= ~(1<<HLM8070_CIOC2);
	}
}

uint8_t HLM8070_Getflags( void )
{
	/*set control bits*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	/*set read mode*/
	HLM8070_RW(1);
	/*set execute*/
	HLM8070_E(1);
	/*read input register*/
	unsigned int ui_value=HLM8070_DBPIN;
	/*set writemode*/
	HLM8070_RW(0);
	/*clear execute*/
	HLM8070_E(0);
	/*return value*/
	return ui_value;
}





void HLM8070_Wait_Busy( void )
{

	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	/*set read mode*/
	HLM8070_RW(1);
	/*set execute*/
	HLM8070_E(1);
	/*read input register busy flag*/
	HLM8070_E(0);
	/*execute while busy*/
	while(bit_is_set(HLM8070_DBPIN, HLM8070_DATA7))
	{
		HLM8070_E(1);
		HLM8070_E(0);
	}	
	
	/*set writemode*/
	HLM8070_RW(0);
	
}


void HLM8070_Set_Function_Mode(	bool IO,
			bool FONT,
			bool DT1,
			bool DT2,
			bool RA1,
			bool RA2)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(1,1,IO, FONT, DT1, DT2, RA1, RA2);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Set_Entry_Mode(bool CSRD1,
			bool CSRW,
			bool CSRR,
			bool DSPD1,
			bool DSPW,
			bool DSPR)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,1,CSRD1, CSRW, CSRR, DSPD1, DSPW, DSPR);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Set_Display_Mode(	
                                bool DSPonoff,
                                bool CSRonoff,
                                bool UNDonoff,
                                bool CSRblink,
                                bool CHRblink)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,1, DSPonoff, CSRonoff, UNDonoff, CSRblink, CHRblink);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Move_Start_Address(bool CSR,
			        bool CSRD1,
			        bool DSP,
			        bool DSPD1)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,1,CSR,CSRD1, DSP, DSPD1);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Set_Underline_Mode(bool USRonoff,
			        bool UNDSR)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,1,1,USRonoff,UNDSR);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Write_Underline_Inst(bool UNDSR,
				  bool CSR1)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,1,0,UNDSR,CSR1);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Set_Blinking_Frequency(bool B1,
				    bool B0)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,1,1,B1,B0);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Dsp_Address_Home( void )
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,0,0,1,1);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}

void HLM8070_Cldsp_Home( void )
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,0,0,0,1);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Nop( void )
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DB(0,0,0,0,0,0,0,0);
	/* no execute just do nothing*/
}


uint8_t HLM8070_Read_Cursor_Address( void )
{
	HLM8070_IOC1(1);
	HLM8070_IOC2(1);
	/*set read mode*/
	HLM8070_RW(1);
	/*set execute*/
	HLM8070_E(1);
	/*read input register*/
	unsigned int ui_value=HLM8070_DBPIN;
	/*set writemode*/
	HLM8070_RW(0);
	/*clear execute*/
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
	
	return ui_value;
}



uint8_t HLM8070_Read_Display_Address( void )
{
	
	/*set control bits*/
	HLM8070_IOC1(1);
	HLM8070_IOC2(0);
	/*set read mode*/
	HLM8070_RW(1);
	/*set execute*/
	HLM8070_E(1);
	/*read input register*/
	uint8_t value=HLM8070_DBPIN;
	/*set writemode*/
	HLM8070_RW(0);
	/*clear execute*/
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
	/*return value*/
	return value;
}


uint8_t HLM8070_Read_Ram_Data( void )
{
	
	/*set control bits*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(1);
	/*set read mode*/
	HLM8070_RW(1);
	/*set execute*/
	HLM8070_E(1);
	/*read input register*/
	uint8_t value=HLM8070_DBPIN;
	/*set writemode*/
	HLM8070_RW(0);
	/*clear execute*/
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
	/*return value*/
	return value;
}

void HLM8070_Write_Cursor_Address(uint8_t address)
{
	/*setting instruction and data*/
	HLM8070_IOC1(1);
	HLM8070_IOC2(1);
	HLM8070_RW(0);
	HLM8070_DBPORT=address;
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}



void HLM8070_Write_Start_Address(uint8_t address)
{
	/*setting instruction and data*/
	HLM8070_IOC1(1);
	HLM8070_IOC2(0);
	HLM8070_RW(0);
	HLM8070_DBPORT=address;
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}


void HLM8070_Write_Ram_Data(	bool bit7,
				bool bit6,
				bool bit5,
				bool bit4,
				bool bit3,
				bool bit2,
				bool bit1,
				bool bit0)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(1);
	HLM8070_RW(0);
	HLM8070_DB(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0);
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}
void HLM8070_Write_Char(unsigned char character)
{
	/*setting instruction and data*/
	HLM8070_IOC1(0);
	HLM8070_IOC2(1);
	HLM8070_RW(0);
	HLM8070_DBPORT=character;
	/*executing*/
	HLM8070_E(1);
	HLM8070_E(0);
	/*wait for busy flag*/
	HLM8070_Wait_Busy();
}

void HLM8070_Init()
{
	HLM8070_CDDR   |=(1<<HLM8070_CE)
       		 | (1<<HLM8070_CIOC1)
		 | (1<<HLM8070_CIOC2)
		 | (1<<HLM8070_CRW);
	HLM8070_DDDR = 0x00;
	HLM8070_DBPORT =0x00;
	HLM8070_Set_Display_Mode(1,0,0,0,0);
	HLM8070_Set_Function_Mode(1,1,1,0,0,0);
	HLM8070_Set_Entry_Mode(0,1,0,0,0,0);
	HLM8070_Set_Underline_Mode(0,0);
	HLM8070_Set_Blinking_Frequency(0,1);
	HLM8070_Write_Start_Address(0);
	HLM8070_Cldsp_Home();
}

void HLM8070_Write_String(char* character)
{
	
	for(int charno=0; character[charno]; charno++)
	{
		HLM8070_Wait_Busy();
		HLM8070_Write_Char(character[charno]);
	}
	HLM8070_Wait_Busy();
}

void HLM8070_Cursor_Pos(uint8_t line ,uint8_t column)
{
		switch(line)
		{
			case 0:
				/*line 1*/
				HLM8070_Write_Cursor_Address(0 + column);
				break;
			case 1:
				/*line 2*/
				HLM8070_Write_Cursor_Address(64 + column);
				break;
			case 2:
				/*line 3*/
				HLM8070_Write_Cursor_Address(128 + column);
				break;
			case 3:
				/*line 4*/
				HLM8070_Write_Cursor_Address(192 + column);
				break;
		}
	HLM8070_Wait_Busy();
}

void HLM8070_Clear_Char(uint8_t line ,uint8_t column)
{
	HLM8070_Cursor_Pos(line, column);
	HLM8070_Write_Char(0xFE);
}
