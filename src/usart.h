/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               usart.h
Created on:         22. Februar 2008, 10:53
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
#ifndef _USART_H
#define	_USART_H

#include <avr/io.h>
#include "global.h"
#include "leeprom.h"


#ifdef	__cplusplus
extern "C" {
#endif

/*Enable interrupt of receiving data*/
void USART_Enable_Interrupt( void );
/*Disable interrupt of receiving data*/
void USART_Disable_Interrupt( void );
/*Standart functions for USART from datasheet*/
void USART_Init( unsigned int baud );
/*Transmit char data over usart*/
void USART_Transmit( unsigned char data );
/*receive and return data from usart*/
unsigned char USART_Receive( void );
/*clear receiver input*/
void USART_Flush( void );
/*transmit string over usart*/
void USART_Transmit_String(char* character);


#ifdef	__cplusplus
}
#endif

#endif	/* _USART_H */

