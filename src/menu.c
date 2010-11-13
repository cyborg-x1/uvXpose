/*
Copyright (C) 2008 by Radiation Laboratories Development-Crew
DEV@rad-lab.net
File:               menu.c
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

#include "menu.h"

//TODO Add comments 
void MENU_Write_Hardware_Status( void )
{	
    
    HARDWARE_Update();
    
    if(global.hardware != global.hardware_old)
    {
        global.hardware_old=global.hardware;
        for(int tube_no = 0; tube_no <= 3; tube_no++)
        {
            HLM8070_Cursor_Pos(tube_no, 12);
            if(global.hardware & 1<<tube_no)
            {
                HLM8070_Write_Char(0x9B);
                HLM8070_Write_Char(0x9B);
                HLM8070_Write_Char(0x9B);
            }
            else
            {
                HLM8070_Write_Char(0x97);
                HLM8070_Write_Char(0x97);
                HLM8070_Write_Char(0x97);
            }
        }
    }
    HLM8070_Cursor_Pos(2,6);
    if(global.hardware & 1<<4)
    {
        HLM8070_Write_String("[R]");
    }
    else
    {
        HLM8070_Write_String("]R[");
    }   
}



void MENU_Display_Main_Menu( void )
{
	HLM8070_Cursor_Pos(0,2);                /*cursor line 2 sign 3*/
	HLM8070_Write_String("START  TIMER");   /* write string to display*/
	HLM8070_Cursor_Pos(1,1);                /*cursor line 2 sign 2*/
	HLM8070_Write_String("TIME");           /*write string to display*/
	HLM8070_Cursor_Pos(2,1);                /*cursor line 3 sign 2*/
	HLM8070_Write_String("LOAD");           /*write string to display*/
	HLM8070_Cursor_Pos(2,11);               /*cursor line 3 sign 12*/
	HLM8070_Write_String("SAVE");           /*write string to display*/
	HLM8070_Cursor_Pos(3,1);                /*cursor line 4 sign 2*/
	HLM8070_Write_String("HARDWARE-CHECK"); /*write string to display*/
}
void MENU_Display_Run_Screen( void )
{
	HLM8070_Cursor_Pos(0,0);                    /*cursor line 1 sign 1*/
	HLM8070_Write_String(">>>PROCESSING>>>");   /*write string to display*/
	HLM8070_Cursor_Pos(1,4);                    /*cursor line 2 sign 5*/
	HLM8070_Write_String("EXPOSURE");           /*write string to display*/
	HLM8070_Cursor_Pos(2,0);                    /*cursor line 3 sign 1*/
	HLM8070_Write_String("REMAINING");          /*write string to display*/
	HLM8070_Cursor_Pos(3,5);                    /*cursor line 4 sign 6*/
	HLM8070_Write_String("[STOP]");             /*write string to display*/
}
void MENU_Display_Powerloss_Screen( void )
{
	HLM8070_Cursor_Pos(0,1);                    /*cursor line 1 sign 2*/
	HLM8070_Write_String("POWER  FAILURE");     /* write string to display*/
	HLM8070_Cursor_Pos(1,3);                    /*cursor line 2 sign 2*/
	HLM8070_Write_String("DETECTED");           /*write string to display*/
	HLM8070_Cursor_Pos(2,1);                    /*cursor line 3 sign 2*/
	HLM8070_Write_String("WANT TO RESUME ?");   /* write string to display*/
	HLM8070_Cursor_Pos(2,2);                    /*cursor line 4 sign 3*/
	HLM8070_Write_String("RESUME  STOP");       /* write string to display*/
}


void MENU_Display_Tubescreen( void )
{
	HLM8070_Cursor_Pos(0,0);
	HLM8070_Write_String("HARD-");
	HLM8070_Cursor_Pos(1,0);
	HLM8070_Write_String(" WARE");
	HLM8070_Cursor_Pos(2,0);
	HLM8070_Write_String("  -  ");
	

	HLM8070_Cursor_Pos(0,11);
	/*display tube*/
	HLM8070_Write_Char(0x88);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x89);
	HLM8070_Cursor_Pos(1,11);
	/*display tube*/
	HLM8070_Write_Char(0x88);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x89);
	HLM8070_Cursor_Pos(2,11);
	/*display tube*/
	HLM8070_Write_Char(0x88);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x89);
	HLM8070_Cursor_Pos(3,11);
	/*display tube*/
	HLM8070_Write_Char(0x88);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x97);
	HLM8070_Write_Char(0x89);
}

void MENU_Display_ComputerControl( void )
{
	HLM8070_Cursor_Pos(0,4); //cursor line 1 sign 2
	HLM8070_Write_String("LOCKED"); // write string to display
	HLM8070_Cursor_Pos(1,0); //cursor line 2 sign 2
	HLM8070_Write_String("COMPUTER CONTROL"); //write string to display
	HLM8070_Cursor_Pos(3,4); //cursor line 3 sign 2
	HLM8070_Write_String("ONLINE");
}



void MENU_Write_Current_Time_Setting(unsigned int ui_line, unsigned int ui_column)
{
	HLM8070_Cursor_Pos(ui_line, ui_column);
	HLM8070_Write_String(Con_Time_Int_Str(global.time_setting));
}

void MENU_Display_Pause_Screen( void )
{
	
	HLM8070_Cldsp_Home();
	HLM8070_Cursor_Pos(0,0); //cursor line 1 sign 2
	HLM8070_Write_String("EXPOSURE  PAUSED"); // write string to display
	/*move cursor line 2 sign 1*/
	HLM8070_Cursor_Pos(2,0);	
	HLM8070_Write_String("REMAINING: "); //write string to display
	HLM8070_Cursor_Pos(3,0); //cursor line 4 sign 3
	HLM8070_Write_String(" STOPP   RESUME");
	
}

void MENU_Display_Completed_Screen( void )
{
	HLM8070_Cldsp_Home();
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_String("EXPOSURE");// write string to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Cursor_Pos(2,5); //cursor line 2 sign 2
	HLM8070_Write_String("[DONE]"); //write string to display
	HLM8070_Cursor_Pos(3,0); //cursor line 4 sign 3
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_String("COMPLETE");// write string to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
	HLM8070_Write_Char(0x9A); // write char ||| to display
}

void MENU_Write_Current_Prog_Number( void )
{	
	HLM8070_Cursor_Pos(2,7);
	HLM8070_Write_Char((global.current_prog_number / 10)+48);
	HLM8070_Write_Char((global.current_prog_number % 10)+48);
}



void MENU_Write_Selection_Brackets( void )
{
	
	switch(global.device_state)
	{
		case 0:
			/*clear not unused bracket places*/
			if(global.menucount != 0)
			{
				/*remove first selection*/
				HLM8070_Cursor_Pos(0,1);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(0,14);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 1)
			{
				/*remove second selection*/
				HLM8070_Cursor_Pos(1,0);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(1,15);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 2)
			{
				/*remove third selection*/
				HLM8070_Cursor_Pos(2,0);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(2,5);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 3)
			{
				/*remove fourth selection*/
				HLM8070_Cursor_Pos(2,6);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(2,9);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 4)
			{
				/*remove fifth selection*/
				HLM8070_Cursor_Pos(2,10);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(2,15);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 5)
			{
				/*remove sixth selection*/
				HLM8070_Cursor_Pos(3,0);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(3,15);
				HLM8070_Write_Char(0xFE);
			}
			/*display current brackets on current selection*/
			switch(global.menucount)
			{
				case 0:
					/*set first selection*/
					HLM8070_Cursor_Pos(0,1);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(0,14);
					HLM8070_Write_Char(0x5D);
				break;
				case 1:
					/*set second selection*/
					if(global.menusetting)
					{
						HLM8070_Cursor_Pos(1,0);
						HLM8070_Write_Char(0x7F);
						HLM8070_Cursor_Pos(1,15);
						HLM8070_Write_Char(0x7E);
					}
					else
					{
						HLM8070_Cursor_Pos(1,0);
						HLM8070_Write_Char(0x5B);
						HLM8070_Cursor_Pos(1,15);
						HLM8070_Write_Char(0x5D);
					}
				break;
				case 2:
					/*set third selection*/
					HLM8070_Cursor_Pos(2,0);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(2,5);
					HLM8070_Write_Char(0x5D);
				break;
				case 3:
					if(global.menusetting)
					{
						HLM8070_Cursor_Pos(2,6);
						HLM8070_Write_Char(0x7F);
						HLM8070_Cursor_Pos(2,9);
						HLM8070_Write_Char(0x7E);
					}
					else
					{
						HLM8070_Cursor_Pos(2,6);
						HLM8070_Write_Char(0x5B);
						HLM8070_Cursor_Pos(2,9);
						HLM8070_Write_Char(0x5D);
					}
				break;
				case 4:
					/*set fifth selection*/
					HLM8070_Cursor_Pos(2,10);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(2,15);
					HLM8070_Write_Char(0x5D);
				break;
				case 5:
					/*set sixth selection*/
					HLM8070_Cursor_Pos(3,0);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(3,15);
					HLM8070_Write_Char(0x5D);
				break;
				
		}
		break;
		case 3:
			if(global.menucount != 0)
			{	
				/*remove first selection*/
				HLM8070_Cursor_Pos(3,0);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(3,6);
				HLM8070_Write_Char(0xFE);
			}
			if(global.menucount != 1)
			{
				/*remove second selection*/
				HLM8070_Cursor_Pos(3,8);
				HLM8070_Write_Char(0xFE);
				HLM8070_Cursor_Pos(3,15);
				HLM8070_Write_Char(0xFE);
			}
			switch(global.menucount)
			{
				case 0:
					/*set first selection*/
					HLM8070_Cursor_Pos(3,0);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(3,6);
					HLM8070_Write_Char(0x5D);
				break;
				case 1:
					/*set second selection*/
					HLM8070_Cursor_Pos(3,8);
					HLM8070_Write_Char(0x5B);
					HLM8070_Cursor_Pos(3,15);
					HLM8070_Write_Char(0x5D);
				break;
			}
		
	}
	
}

void MENU_Display_Output( void )
{
	if(global.device_state != global.device_old_state)
	{
		global.old_prog_number = 0xFF;
		/*clear last_menucount*/
		global.menucount_old = 0xFF;
		/*clear menucount_old*/
		global.menucount = 0;
		/*clear display and home cursor*/
		HLM8070_Cldsp_Home();
		/*clear variables for menu setting*/
		global.menusetting = 0;
		/*set old to current state*/
		global.device_old_state=global.device_state;
		/*display non dynamic text*/
		switch(global.device_state)
		{
			case 0:
				MENU_Display_Main_Menu();
				MENU_Write_Current_Time_Setting(1, 10);
			break;
			
			case 1:
				MENU_Display_Run_Screen();
			break;
			
			case 2:
				MENU_Display_Completed_Screen();
			break;
	
			case 3:
				MENU_Display_Pause_Screen();
			break;
			
			case 4:
				MENU_Display_Tubescreen();
				HLM8070_Cursor_Pos(3,0);
				HLM8070_Write_String("CHECK");
			break;
			case 5:
				MENU_Display_ComputerControl();
			break;
		}
	}

	switch(global.device_state)
	{
		case 0: 	/*Main menu*/

			if(global.time_setting != global.timer_state)
			{
				global.timer_state=global.time_setting;
				MENU_Write_Current_Time_Setting(1, 10);
			}
			if(global.old_prog_number != global.current_prog_number)
			{
				global.old_prog_number = global.current_prog_number;
				MENU_Write_Current_Prog_Number();
			}
			if(global.menucount_old != global.menucount && global.menusetting_old != global.menusetting);
			{
				global.menucount_old = global.menucount;
				global.menusetting_old = global.menusetting;
				MENU_Write_Selection_Brackets();
			}
		break;
		
		case 1:	/*Timer running*/
			HLM8070_Cursor_Pos(2,11);
			uint16_t remainingtime=global.time_setting-global.timer_state;
			HLM8070_Write_String(Con_Time_Int_Str(remainingtime));
		break;
		
		case 2:	/*Exposure finished*/
			_delay_ms(50);
			PORTD|=(1<<PD7);
			_delay_ms(50);
			PORTD&=~(1<<PD7);
		break;

		case 3:	/*Timer paused*/
			HLM8070_Cursor_Pos(2,11);
			/*calculate remaining time*/
			uint16_t remainingtime2 = global.time_setting - global.timer_state;
			HLM8070_Write_String(Con_Time_Int_Str(remainingtime2));
			MENU_Write_Selection_Brackets();
			MENU_Write_Selection_Brackets();
		break;
		
		case 4:	/*Hardwarecheck*/
                        MENU_Write_Hardware_Status();
		break;
		
		case 5:	/*Computercontrol*/
			/*if no keep alive or other command within 1s then
			switch off tubes and return to main*/
			for(global.katime=0;global.katime <= 100; global.katime++)
			{
				_delay_ms(10);
			}
			RELAY_Off();
			global.device_state=0;
		break;
	}
}



/*###############
 BUTTON INTERRUPT
#################*/

ISR(INT1_vect)
{
    switch(global.device_state)
    {
	case 0: /*commands on main menu*/
            /*execute main menu functions*/
            switch(global.menucount)
            {
		case 0: /*start timer*/
                    /*activate_exposure*/
                    RELAY_On();
                    /*Set state to expose(running)*/
                    global.device_state=1;
                    /*clear current timer value*/
                    global.timer_state=0;
                    /*start timer*/
                    TIMER_Start();
                break;
		case 1: /*timer setting*/
                    if(global.menusetting)
                    {
			global.menusetting = 0;
                    }
                    else
                    {
                        global.menusetting = 1;
                    }
		break;
        	case 2:/*load*/
                    global.time_setting=LEEPROM_Load_Time_Setting(global.current_prog_number);
		break;
                case 3:/*choose programm*/
                    if(global.menusetting)
                    {
			global.menusetting = 0;
                    }
                    else
                    {
			global.menusetting = 1;
                    }
                    break;
                    case 4:/*save*/
                        LEEPROM_Save_Time_Setting(global.current_prog_number, global.time_setting);
                    break;
                    case 5:/*hardwarecheck*/
                        global.device_state=4;
                    break;
            }
	break;
	case 1:
            /*stop on run screen*/
            RELAY_Off();
            TIMER_Stop();
            global.device_state=3;
	break;
	case 2:
            /*back to main menu state*/
            global.device_state=0;
	break;
	case 3: /*button commands on paused screen*/
            switch(global.menucount)
            {
                case 0:
                    /*goto main menu*/
                    global.device_state=0;
                    /*clear count*/
                    global.timer_state=0;
		break;
		case 1:
                    /*activate_exposure*/
                    RELAY_On();
                    TIMER_Start();
                    global.device_state=1;
		break;
            }
	break;
	case 4:
            /*back to main menu state*/
            global.device_state=0;
            break;
    }
}

