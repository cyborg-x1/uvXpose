/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               readadc.c
Created on:         21. Februar 2008, 23:25
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

#include "readadc.h"

uint16_t ADC_Read_Channel(uint8_t channel)
{
    uint16_t result;
    /*Frequency devision set to 32*/
    ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0); 
    /*select channel*/
    ADMUX = channel;
    ADMUX |= (1<<REFS1) | (1<<REFS0); /* use internal reference*/
for(int i=0; i<=4;i++)
{
    /*do dummy convertings*/
    ADCSRA |= (1<<ADSC);
    /*wait for finish*/
    while(bit_is_set(ADCSRA, ADSC));
    result = ADCW; 
    /*clear result*/
    result = 0;
}

    /*do real conversion*/
    ADCSRA |= (1<<ADSC);
    /*wait for finish*/
    while(bit_is_set(ADCSRA, ADSC));
    /*set result*/
    result += ADCW; 
    return result;
}
