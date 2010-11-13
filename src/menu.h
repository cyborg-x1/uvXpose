/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               menu.h
Created on:         24. Februar 2008, 14:22
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
#ifndef _MENU_H
#define	_MENU_H

#ifdef	__cplusplus
extern "C" {
#endif


#include <avr/io.h>
#include "additions.h"
#include "global.h"
#include "hlm8070lw8.h"
#include "timer.h"
#include "relay.h"
#include "hardwarecheck.h"

//TODO 
void MENU_Write_Hardware_Status( void );
void MENU_Display_Main_Menu( void );
void MENU_Display_Run_Screen( void );
void MENU_Display_Powerloss_Screen( void );
void MENU_Display_Tubescreen( void );
void MENU_Display_ComputerControl( void );
void MENU_Write_Current_Time_Setting(unsigned int ui_line, unsigned int ui_column);
void MENU_Display_Pause_Screen( void );
void MENU_Display_Completed_Screen( void );
void MENU_Write_Current_Prog_Number( void );
void MENU_Write_Selection_Brackets( void );
void MENU_Display_Output( void );



 
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* _MENU_H */

