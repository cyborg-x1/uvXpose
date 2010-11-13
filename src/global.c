/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               global.c
Created on:         24. Februar 2008, 18:14
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

#include "global.h"

void GLOBAL_Init( void )
{
    global.device_state=0;
    global.device_old_state=0xFF;
    global.time_setting=1;
    global.timer_state=0;
    global.menucount=0;
    global.menucount_old=0xFF;        
    global.menusetting=0;
    global.menusetting_old=0xFF;
    global.current_prog_number=0;
    global.old_prog_number=0xFF;
    global.serial_char_count=0;
    global.hardware=0;
    global.hardware_old=0xFF;
}
