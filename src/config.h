/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               config.h
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
#ifndef _CONFIG_H
#define	_CONFIG_H


#ifdef	__cplusplus
extern "C" {
#endif


/*Definitions*/
#ifndef F_CPU
    #define F_CPU 1000000UL
    #warning F_CPU not defined, now set to 1 Mhz
#endif
    
    
#define _HLM8070_EXT_PORT_CONFIG_
/*Definition of display datalines*/
#define HLM8070_DBPORT 	PORTC /**/
#define HLM8070_DBPIN	PINC
#define HLM8070_DDDR	DDRC
#define HLM8070_DATA0 	PC0
#define HLM8070_DATA1 	PC1
#define HLM8070_DATA2 	PC2
#define HLM8070_DATA3 	PC3
#define HLM8070_DATA4 	PC4
#define HLM8070_DATA5 	PC5
#define HLM8070_DATA6 	PC6
#define HLM8070_DATA7 	PC7

/*Definition of display control lines*/
#define HLM8070_CPORT	PORTB
#define HLM8070_CDDR	DDRB
#define HLM8070_CE	PB3
#define HLM8070_CIOC1	PB1
#define HLM8070_CIOC2	PB5
#define HLM8070_CRW	PB0

/*Definition of relay connection*/
#define _RELAY_EXT_PORT_CONFIG_ 
#define RELAY_PORT      PORTD
#define RELAY_PIN       PIND
#define RELAY_DDR       DDRD
#define RELAY_SENSOR_P  PD5
#define RELAY_TRIGGER_P PD6

/*Definition of powerfail connection*/    
#define _POWER_FAIL_EXT_CONFIG_
#define POWER_FAIL_PIN PINB 
#define POWER_FAIL_DDR DDRB  
#define POWER_FAIL_P   PB2

    
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>   

#include "global.h"
#include "hlm8070lw8.h"
#include "relay.h"     
#include "timer.h"
#include "additions.h"
#include "leeprom.h"
#include "usart.h"
#include "serial.h"
#include "readadc.h"
#include "hardwarecheck.h"
#include "relay.h"
#include "menu.h"
#include "impulse.h"

#ifdef	__cplusplus
}
#endif

#endif	/* _CONFIG_H */

