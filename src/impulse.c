/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               impulse.c
Created on:         24. Februar 2008, 20:31
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

/*rotary impulse emitter*/

#include "impulse.h"

void IMPULSE_Init( void )
{
    /*Controlregister-settings*/
    /*Interrupt on falling edge of Channel A*/
    MCUCR |= (1<<ISC01) | (0<<ISC00) ;
    MCUCR |= (1<<ISC01) | (0<<ISC00) ;
    /*Interrupt on falling edge of Button (high while not pressed)*/
    MCUCR |= (1<<ISC11) | (0<<ISC10) ;	
    MCUCR |= (1<<ISC11) | (0<<ISC10) ;	
    /*Button interrupt in GICR*/
    GICR |= (1<<INT1);
    /*set PD2 -PD4 as input*/
    DDRD &= ~((1<<PD2) |(1<<PD3) |(1<<PD4));
    DDRB |=0xFF;
}

void IMPULSE_Rotation_Interrupt_Enable( void )
{
    /*enable interrupt 0*/
    GICR |= (1<<INT0);
}

void IMPULSE_Rotation_Interrupt_Disable( void )
{
    /*disable interrupt 0*/
    GICR &= ~(1<<INT0);
}



/*interrupt rotation*/
ISR(INT0_vect)
{
    if(bit_is_set(PIND,PD4))  /*if it turns right*/
    {
        switch(global.device_state) /*mode switch*/
        {
            case 0:/*main menu*/
                if(!global.menusetting)
                {
                    if(global.menucount < 5)
                    {
                        /*next selection*/
                        global.menucount++;
                    }
                    else
                    {
                        /*return to first selection*/
                        global.menucount = 0;
                    }
                }
                else
                {
                    switch(global.menucount)
                    {
                        case 1: /*timer setting*/
                            if(global.time_setting < 60*60)
                            {
                                global.time_setting++;
                            }
                            else
                            {
                                global.time_setting = 1; //60 Minutes
                            }
                            break;
                        case 3: /*choose programm*/
                            if(global.current_prog_number < 20)
                            {
                                global.current_prog_number++;
                            }
                            else
                            {
                                global.current_prog_number = 0; //Prog 0
                            }
                        break;
                    }
                }
            break;
            case 1:
                /*nothing to do here*/
            break;
            case 2:
                /*nothing to do here*/
            break;
            case 3:
                if(global.menucount < 1)
                {
                    /*next selection*/
                    global.menucount++;
                }
                else
                {
                    /*return to first selection*/
                    global.menucount = 0;
                }
            break;
        }
    }
    else	/*if it turns left*/
    {
        switch(global.device_state)
	{
            case 0:
                if(!global.menusetting)
		{
                    if(global.menucount > 0)
                    {
                        global.menucount--;
                    }
                    else
                    {
                     global.menucount = 5;
                    }
				
		}
		else
		{
                    switch(global.menucount)
                    {
			case 1: /*timer setting*/
			if(global.time_setting > 1)
			{
                            global.time_setting--;
			}
			else
			{
                            global.time_setting = 60*60; //60 Minutes
			}
			break;
			case 3: /*choose programm*/
			if(global.current_prog_number > 0)
			{
                            global.current_prog_number--;
			}
			else
			{
                            global.current_prog_number = 20; //Prog 20
			}
			break;
                    }
		}
            break;
            case 1:
                /*nothing to do here*/
            break;
            case 2:
                /*nothing to do here*/
            break;
            case 3:
            	if(global.menucount > 0)
                {
                    /*next selection*/
                    global.menucount--;
		}
		else
		{
                    /*return to first selection*/
                    global.menucount = 1;
		}
            break;
        }
    }
}




