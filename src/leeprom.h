/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               leeprom.h
Created on:         21. Februar 2008, 20:23
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
#ifndef _LEEPROM_H
#define	_LEEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif


#include <avr/eeprom.h>
#include <inttypes.h>
#include "global.h"
#include "additions.h"

 
#ifndef EEMEM
#define EEMEM  __attribute__ ((section (".eeprom")))
#endif

/*Saves the current time 
 * setting to eeprom into 
 * selected prog slot*/    
void LEEPROM_Save_Time_Setting(uint8_t prog, uint16_t value);
/*Loads a time setting from a prog slot*/
uint16_t LEEPROM_Load_Time_Setting(uint8_t prog);    
/*Saves time_setting and timer state to eeprom*/
void LEEPROM_Anounce_Powerfail( void );    
/*Checks if a Powerfail occured*/
bool LEEPROM_Check_Powerfail( void );
/*Resumes a exposure interrupted through powerfail*/
void LEEPROM_Resume_Powerfail( void );

#ifdef	__cplusplus
}
#endif

#endif	/* _EEPROM_H */

