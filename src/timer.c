/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               timer.c
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

#include "timer.h"
#include "relay.h"
 
char *Con_Time_Int_Str(uint16_t contime)
{
    if(contime <= 3600)
    {
        static char chartime[6];
        uint8_t minutes10 = (contime / 60 / 10);
        uint8_t minutes1  = (contime / 60) % 10;
        uint8_t seconds10 = (contime / 10) % 6;
        uint8_t seconds1  = contime%10;

        chartime[0]=(char)minutes10 + 48;
        chartime[1]=(char)minutes1 + 48;
        chartime[2]=(char)0x3A /*No ASCII Standard for :*/;
        chartime[3]=(char)seconds10 + 48;
        chartime[4]=(char)seconds1 + 48; 
        chartime[5]='\0';

        return chartime;
    }
    else 
    {
            return "ERRT1";
    }
}

void TIMER_Init( void )
{
    /*clear interrupts for accessing Output Compare Register*/
    INTERRUPT_Clear();
    /*set OCR1 1 second on current clock*/
    OCR1A |= _TIMER_CLOCK_1SEC_TOP_;
    /*reactivate interrupts*/
    INTERRUPT_Restore();
    /*initialise variable for number of received chars from usart*/
    global.serial_char_count=0;
}
void TIMER_Start( void )
{
    /*clear interrupts for accessing Output Compare Register*/
    INTERRUPT_Clear();
    /*start value*/
    TCNT1=0x0000;
    /*reactivate interrupts*/
    INTERRUPT_Restore();
    /*set Interrupt for timer 1*/
    TIMSK |= (1<<OCIE1A);
    /*Timer Counter Control Register B Timer 1*/
    TCCR1B |=(1<<WGM12) | (1<<CS12) | (1<<CS10) ;
}

void TIMER_Stop( void )
{
    /*disable Interrupt for timer 1*/
    TIMSK &= ~(1<<OCIE1A);
    /*Timer Counter Control Register B Timer 1*/
    TCCR1B = 0x00;
}

ISR(TIMER1_COMPA_vect)
{
    /*raise timer state*/
     global.timer_state++;
    /*timer_state - endvalue compare*/
    if(global.timer_state == global.time_setting)
    {
            /*stop timer*/
            TIMER_Stop();
            /*clear timer*/
            global.timer_state=0;
            /*stop exposure*/
            RELAY_Off();	
            /*display complete info*/
            global.device_state = 2;
    }
}
