/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               relay.c
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

#include "relay.h"

void RELAY_Init( void )
{
    RELAY_DDR &= ~(1<<RELAY_SENSOR_P);
    RELAY_DDR |= (1<<RELAY_TRIGGER_P);
    RELAY_PORT &= ~(1<<RELAY_SENSOR_P); 
}

void RELAY_On( void )
{
    RELAY_PORT |= (1<<RELAY_TRIGGER_P);
}

void RELAY_Off( void )
{
    RELAY_PORT &= ~(1<<RELAY_TRIGGER_P);
}
        
bool RELAY_Check( void )
{   
    return bit_is_set(RELAY_PIN,RELAY_SENSOR_P);
}
