/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               serial.c
Created on:         22. Februar 2008, 10:54
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

#include "serial.h"


void SERIAL_Transmit_Programs( void )
{
    
    for(uint8_t prog_no=0; prog_no <= 20; prog_no++)
    {
        USART_Transmit(':');
	USART_Transmit(LEEPROM_Load_Time_Setting(prog_no));	
    }
}

void SERIAL_Transmit_Remaining_Time( void )
{
	uint8_t remaining_time = global.time_setting - global.timer_state;
	USART_Transmit_String(Con_Time_Int_Str(remaining_time));
	USART_Transmit_String("\n");
}

void SERIAL_Return_Error( void )
{
	USART_Transmit(0x01);
	USART_Transmit('\n');
}

void SERIAL_Return_Ack( void )
{
	USART_Transmit(0x00);
	USART_Transmit('\n');
}



void SERIAL_Command_Handler(char* receivedC) // pointer on pointer ???????
{
	


    
    char command[31];
    char value[30];    
    uint8_t value_len=0;
    Separate_String_By_Char(receivedC, ' ', command, value);
    
/*#################################
		Serial Command Definition
#################################*/
        //TODO REMOVE
	USART_Transmit_String(command);
        USART_Transmit(':');
        USART_Transmit_String(value);
        USART_Transmit('#');
        
        
	if(!strcmp(command,"QP")) /*Query Progs*/
	{
		if(!strcmp(value,""))
		{
			SERIAL_Transmit_Programs();
			SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"ST")) /*Start timer*/
	{
		if(!strcmp(value,""))
		{
			if(global.device_state==0)/*if in main menu*/
			{
				/*activate_exposure*/
				RELAY_On();
				/*goto running mode*/
				global.device_state=1;
				/*clear timer state*/
				global.timer_state=0;
				/*activate timer*/
				TIMER_Start();
				
				SERIAL_Return_Ack();
				
			}
			else if(global.device_state==3)/*if timer paused*/
			{
				/*activate_exposure*/
				RELAY_On();
				/*switch back to running mode*/
				global.device_state=1;
				/*restart timer*/
				TIMER_Start();
				/*serial return 0*/
				SERIAL_Return_Ack();
			}
			else
			{	
				/*serial return 1*/
				SERIAL_Return_Error();
			}
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"SC")) /*Stopp and Clear timer*/
	{
		if(!strcmp(value,""))
		{
			if((global.device_state==1 || global.device_state==2) )/*if timer running or timer finished*/
			{
				RELAY_Off();
				TIMER_Stop();
				global.timer_state=0;
				global.device_state=0;
				SERIAL_Return_Ack();
			}
			else
			{
				SERIAL_Return_Error();
			}
		}
	}
		
	else if(!strcmp(command,"QT")) /*Query time setting*/
	{
		if(!strcmp(value,""))
		{
			USART_Transmit(global.time_setting);
			SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"QR")) /*Query remaining time*/
	{
		if(!strcmp(value,""))
		{
			USART_Transmit(global.time_setting-global.timer_state);
			SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"RE")) /*reset device*/
	{
		if(!strcmp(value,""))
		{
			//TODO
			USART_Transmit_String("TODO SOFTRESET");
			SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"QS")) /*query state*/
	{
		if(!strcmp(value,""))
		{
                    if(global.device_state != 2)
                    {
			USART_Transmit(global.device_state);
			SERIAL_Return_Ack();
                    }
                    else
                    {   
                        /*if exposure is done timer_state is cleared
                         *instantly thats why we need this here otherwise
                         *you would get time_setting when it is showing
                         *completed screen...
                         */
                        USART_Transmit(0);
			SERIAL_Return_Ack();
                    }
                }
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"CT"))
	{
		if(!strcmp(value,""))
		{
			HARDWARE_Update();
                        USART_Transmit(global.hardware);
                        SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"CC")) /*Computer Control*/
	{
		if(!strcmp(value,"") && global.device_state==0 && global.device_state !=5)
		{
			global.device_state=5;
			global.katime=0;
			SERIAL_Return_Ack();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"KA")) /*connection keep alive*/
	{
		if(!strcmp(value,"") && global.device_state==5)
		{
			global.katime=0;
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"ON")) /*switch on tubes*/
	{
		if(!strcmp(value,"") && global.device_state==5)
		{
			global.katime=0;
			RELAY_On(); 
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"OF")) /*switch off tubes*/
	{
		if(!strcmp(value,"") && global.device_state==5)
		{
			global.katime=0;
			RELAY_Off(); 
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"DC")) /*disconnect*/
	{
		if(!strcmp(value,"") && global.device_state==5)
		{
			global.device_state=0;
                        RELAY_Off();
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"TS")) /*set time seconds*/
	{
		value_len=strlen(value)-1;
                
		if(strcmp(value,"") && value_len<4 && global.device_state != 1)
		{
			uint16_t ntime=6;      
                        USART_Transmit_String(value);
                        ntime=String2Integer(value);                        
			if(ntime > 0 && ntime <= 3600)
			{
				global.time_setting=ntime;
				SERIAL_Return_Ack();
			}
			else
			{       
				SERIAL_Return_Error();
			}
		}
		else
		{
			SERIAL_Return_Error();
		}
	}
	else if(!strcmp(command,"TM")) /*set time minutes:seconds*/
	{
            
	}
	else if(!strcmp(command,"SP")) /*Set programm*/
	{
            
		if(strcmp(value,""))
		{
                    if(strlen(value) <= 7)
                    {
                        char progs[8];
                        char times[7];
                        Separate_String_By_Char(value,32, progs, times);
                        if(strlen(progs) >=1 && strlen(progs) <=2  && strlen(times) >= 1)
                        {
                            //TODO
                            uint16_t prog_number=String2Integer(progs);
                            uint16_t time_value=String2Integer(times);                            
                            if(time_value >= 0 && time_value <= 3600
                                 && prog_number >= 0 && prog_number <= 20)
                            {
                                
                                LEEPROM_Save_Time_Setting(prog_number,time_value);
                                SERIAL_Return_Ack();
                            }
                            else
                            {
                                SERIAL_Return_Error();
                            }
                                    
                        }
                        else
                        {
                            SERIAL_Return_Error();
                        }
                    }
                    else
                    {
                        SERIAL_Return_Error();
                    }
                    
                }
		else
		{
			SERIAL_Return_Error();
		}
	}
	else
	{
		SERIAL_Return_Error();
	}
}


void SERIAL_Receive( void )
{
	/*declare command string and complete char count*/
	static char received_string[31];
		while(bit_is_set(UCSRA , RXC))
	{
            /*add current UDR to command-string*/
            received_string[global.serial_char_count]=UDR;
            /*increase char count*/
            global.serial_char_count++;
            /*check if current char count is <CR>*/
	if(received_string[global.serial_char_count-1]=='\r')
	{
            received_string[global.serial_char_count-1]='\0'; 
            SERIAL_Command_Handler(received_string);
            memset((char *) received_string, 0, 31*sizeof(char)); //clear command string
            global.serial_char_count=0;       //clear count
	}
	if(global.serial_char_count>=30)
	{
            memset((char *) received_string, 0, 31*sizeof(char));
            global.serial_char_count=0;
	}
    }
}
//TODO header entry
ISR(USART_RXC_vect)
{
	INTERRUPT_Clear();
	/*receive commands*/
	SERIAL_Receive();	
        INTERRUPT_Restore();
}


