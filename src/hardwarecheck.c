/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               hardwarecheck.c
Created on:         21. Februar 2008, 23:08
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

#include "hardwarecheck.h"

void HARDWARE_Init( void )
{
    
}

void HARDWARE_Update( void )
{
    /*check each tube if it is
    on and then set bit to 1(on) or 0(off)*/
    for(uint8_t tube_no = 0;tube_no <=3; tube_no++)
    {
        
        /*ADC Readings: Check if tubes are lit*/
        if(ADC_Read_Channel(tube_no)>300)
        {
            global.hardware |= (1<<tube_no);
	}
	else
	{
            global.hardware &= ~(1<<tube_no);
	}
        
    }
    if(RELAY_Check())
    {
        global.hardware |= (1<<4); 
    }
    else
    {
        global.hardware &= ~(1<<4);
    }
    if(bit_is_set(POWER_FAIL_PIN,POWER_FAIL_P))
    {
        global.hardware |= (1<<5); 
    }
    else
    {
        global.hardware &= ~(1<<5);
    }
}


