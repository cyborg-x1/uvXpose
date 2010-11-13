/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               hardwarecheck.h
Created on:         21. Februar 2008, 23:08
Belongs to project: //TODO <insert projectname>

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
#ifndef _HARDWARECHECK_H
#define	_HARDWARECHECK_H

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef _HAS_CONFIG_
    #include "config.h"
#endif


#include <stdbool.h>
#include "global.h"
#include "relay.h"
#include "timer.h" 
#include "readadc.h"
    

#ifndef _POWER_FAIL_EXT_CONFIG_
    #define POWER_FAIL_PIN PINB 
    #define POWER_FAIL_DDR DDRB  
    #define POWER_FAIL_P   PB2
#endif

#ifndef F_CPU
 #warning F_CPU not defined  
 #warning F_CPU now set to 1 Mhz
 #define F_CPU 1000000UL
#endif
    
    
/*This function reports 0 when all hardware is working
 * Errors:
 * Bit 1 - 4: Tube 1 - 4
 * Bit 5:     Relay
 * Bit 6:     Power Source
 * Bit 7 & 8: Reserved
 */
void HARDWARE_Init( void );
void HARDWARE_Update( void );


#ifdef	__cplusplus
}
#endif

#endif	/* _HARDWARECHECK_H */

