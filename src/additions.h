/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               additions.h
Created on:         21. Februar 2008, 21:56
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
#ifndef _ADDITIONS_H
#define	_ADDITIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include "global.h"
#include <string.h>
    
uint16_t String2Integer(char *string);

void Separate_String_By_Char(char string[], char separator, char output1[], char output2[]);

void INTERRUPT_Clear( void );

void INTERRUPT_Restore( void );

#ifdef	__cplusplus
}
#endif

#endif	/* _ADDITIONS_H */

