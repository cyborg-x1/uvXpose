/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               timer.h
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
#ifndef _TIMER_H
#define	_TIMER_H


#ifdef	__cplusplus
extern "C" {
#endif

#ifdef _HAS_CONFIG_
    #include "config.h"
#endif
        
#ifndef F_CPU
 #warning F_CPU not defined  
 #warning F_CPU now set to 1 Mhz
 #define F_CPU 1000000UL
#endif

#define _TIMER_CLOCK_1SEC_TOP_  974*16  //TODO CALCULATION  

    
    
#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <string.h>
#include <avr/interrupt.h>
#include "global.h"    
#include "additions.h"


/*convert seconds to MM:SS (max 3600)*/
char *Con_Time_Int_Str(unsigned int contime);
/*timer setting and devider*/
void TIMER_Init( void );
void TIMER_Start( void );
void TIMER_Stop( void );

/*Interruptvector for timer compare match 
 * !!do NOT uncomment already defined in avrlib!!*/
/*ISR(TIMER1_COMPA_vect)*/



#ifdef	__cplusplus
}
#endif

#endif	/* _TIMER_H */

