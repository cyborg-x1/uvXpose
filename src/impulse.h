/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               impulse.h
Created on:         24. Februar 2008, 20:31
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
#ifndef _IMPULSE_H
#define	_IMPULSE_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include <avr/io.h>
    #include "global.h"
    #include "timer.h"
    #include "leeprom.h"
    
    void IMPULSE_Init( void );
    void IMPULSE_Rotation_Interrupt_Enable( void );
    void IMPULSE_Rotation_Interrupt_Disable( void );

    
    
#ifdef	__cplusplus
}
#endif

#endif	/* _IMPULSE_H */

