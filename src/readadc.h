/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               readadc.h
Created on:         21. Februar 2008, 23:37
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
#ifndef _READADC_H
#define	_READADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef _HAS_CONFIG_
    #include "config.h"
#endif
 

    
#include <avr/io.h>
#include <util/delay.h>
    
    
/*Reads the requested adc channel*/
uint16_t ADC_Read_Channel(uint8_t channel);


#ifdef	__cplusplus
}
#endif

#endif	/* _READADC_H */

