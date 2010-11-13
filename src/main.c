/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               main.c
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


#include "config.h"

/*
 *  This is the main file of the uvXpose atmega16 source
 */
int main( void ) 
{
    /*Device initialisation*/
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);
    /*wait 5 secs for all interupts to calm down*/
    for(uint8_t wait_ms=0; wait_ms <= 50; wait_ms++) _delay_ms(100);
    /*LCD*/
    HLM8070_Init();
    TIMER_Init();
    GLOBAL_Init();
    IMPULSE_Init();    
    HARDWARE_Init();
    USART_Init(207);
    IMPULSE_Rotation_Interrupt_Enable();
    USART_Enable_Interrupt();
    /*load first prog*/
    global.time_setting=LEEPROM_Load_Time_Setting(0);  
    sei();
    
    while(1)
    {
        MENU_Display_Output();
    }
    return 0;
}

