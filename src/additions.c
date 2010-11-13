/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               additions.c
Created on:         21. Februar 2008, 21:56
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

#include "additions.h"


void Separate_String_By_Char(char string[], char separator, char output1[], char output2[])
{
	/*save string into two seperate arrays*/
	uint8_t string_len = strlen(string)-1;
        uint8_t char_no;
	for(char_no = 0;char_no<=string_len && string[char_no] != separator; char_no++)
	{
		output1[char_no]=string[char_no];
	}
	output1[char_no]='\0';
        char_no++;
        uint8_t char_no2;
	for(char_no2=0;char_no<=string_len;char_no++, char_no2++)
	{
		output2[char_no2]=string[char_no];
	}
	output2[char_no2]='\0';
}


uint16_t String2Integer(char *string)
{
    int8_t string_len=strlen(string)-1;
    uint16_t result=0;
    uint16_t valency=1;
    for(uint8_t valcount=0; valcount<=string_len-1; valcount++) 
    {
        valency *= 10;	
    }
    for(uint8_t char_no=0;string[char_no] != '\0';char_no++)
    {
       
        if(string[char_no]>=48 && string[char_no]<=57)
        {
            result+=(string[char_no]-48)*valency;
        }
        else
        {
            return -1;
        }
        if(valency == 1)
        {
            break;
        }
        valency /= 10;
    }
    return result;	
}

void INTERRUPT_Clear( void )
{
    global.sreg=SREG;
    cli();
}

void INTERRUPT_Restore( void )
{
    SREG=global.sreg;
}

        

