/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               relay.h
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
#ifndef _RELAY_H
#define	_RELAY_H


#ifdef _HAS_CONFIG_
    #include "config.h"
#endif

/*if defined following section 
 * must be found in config*/ 

#ifndef _RELAY_EXT_PORT_CONFIG_ 
    #define RELAY_PORT      PORTD /*PORT where relay is connected to*/
    #define RELAY_PIN       PIND  /*PIN of PORT*/
    #define RELAY_DDR       DDRD  /*DDR of PORT*/
    #define RELAY_SENSOR_P  PD5   /*Sensor to check if relay switches*/
    #define RELAY_TRIGGER_P PD6   /*Output to trigger relay*/
#endif
#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <inttypes.h>



#ifdef	__cplusplus
extern "C" {
#endif

/*This function sets the DDR register for sensor and trigger ic-pins */
void RELAY_Init( void );
/*This function activates the relay*/
void RELAY_On( void );
/*This function deactivates the relay*/
void RELAY_Off( void );
/*This function checks if relay is on*/        
bool RELAY_Check( void );



#ifdef	__cplusplus
}
#endif

#endif	/* _RELAY_H */
