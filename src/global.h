/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               globals.h
Created on:         21. Februar 2008, 21:34
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
#ifndef _GLOBAL_H
#define	_GLOBAL_H

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#ifdef	__cplusplus
extern "C" {
#endif
   
/*The struct for global variables and functions*/
typedef struct global_s
{
    /*current state of device*/
    uint8_t device_state;
    /*State list:
     *0 Main menu
     *1 Manual exposure in progress
     *2 Manual exposure completed
     *3 Manual exposure paused
     *4 Tubecheck
     *5 Computer controlled mode (manual off)
     *6 Tube error / Relay error
     *7 Powerloss-Resume from last manual exposure 
    */ 
    
    /*former device_state 
     * (is used to rewrite display on change
     * of device state)
     */
    uint8_t device_old_state;
    /*Current time setting (manual mode) */
    uint16_t time_setting; 
    /*time in seconds since timer start*/
    uint16_t timer_state;
     
    /*variables for where you are in current menu*/
    uint8_t menucount;
    uint8_t menucount_old;
    /*veriables for if you have selected a regulator*/
    bool menusetting;
    bool menusetting_old;
    /*variables of the current selected program*/
    uint8_t  current_prog_number;
    uint8_t  old_prog_number;
    /*variable for storing hardware values*/
    uint8_t  hardware;
    uint8_t  hardware_old;
    /*variable for connection keep alive time*/
    uint8_t  katime;
    /*variable for counting chars received over serial iface 
     after last \r */
    uint8_t  serial_char_count;
    /*backup for the SREG register*/
    uint8_t  sreg;
}global_t;

global_t global;

void GLOBAL_Init( void );


       
    
#ifdef	__cplusplus
}
#endif

#endif	/* _GLOBALS_H */

