/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               leeprom.c
Created on:         21. Februar 2008, 20:25
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
#include "leeprom.h"


uint16_t ee_prog_array[21] EEMEM;
uint16_t ee_power_fail_array[2] EEMEM;

void LEEPROM_Save_Time_Setting(uint8_t prog, uint16_t value)
{
    if(value <= 3600 && value > 0 && prog <= 20)
    {
        INTERRUPT_Clear();
        eeprom_write_word(&ee_prog_array[prog], value);
        INTERRUPT_Restore();
    }
}

uint16_t LEEPROM_Load_Time_Setting(uint8_t prog)
{	
    INTERRUPT_Clear();
    uint16_t loaded_time = eeprom_read_word(&ee_prog_array[prog]);
    if(loaded_time > 3600)
    {
    	loaded_time=1;
    }
    INTERRUPT_Restore();
    return loaded_time;
}

void LEEPROM_Anounce_Powerfail( void )  
{
    INTERRUPT_Clear();
    eeprom_write_word(&ee_power_fail_array[0],global.timer_state);
    eeprom_write_word(&ee_power_fail_array[1],global.time_setting);
    INTERRUPT_Restore();
}

bool LEEPROM_Check_Powerfail( void )
{    
    uint16_t value;
    uint16_t value2;
    INTERRUPT_Clear();
    value=eeprom_read_word(&ee_power_fail_array[0]);
    if(value<=3600 && value >0)
    {
        value2=eeprom_read_word(&ee_power_fail_array[1]);
        if(value2<=3600 && value2>0)
        {
            INTERRUPT_Restore();
            return 1;
        }
    }    
    INTERRUPT_Restore();
    return 0;
} 

void LEEPROM_Clear_Powerfail( void )
{
    INTERRUPT_Clear();
    //TODO
    INTERRUPT_Restore();
}

