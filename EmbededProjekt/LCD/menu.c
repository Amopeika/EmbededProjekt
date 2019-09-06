/**
*	Titel: menu.c
*
*	Author: Kevin Pike Darmer
*
*  Key|Menu Display and Choices
*  ---|-------------------------
*	1 | 1
*	2 | 2
*	3 | 3
*	4 | 4
*	5 | 5
*	6 | 6
*	7 | 7
*	8 | 8/NEXT
*	9 | 9/BACK
*	0 | 0
*	* | Accept
*	# | Enter
*	A | Temparatur
*	B | Fan Speed
*	C |	RGB Coloring
*	D | Back to Main Menu
*/
#include "menu.h"
#include "../LCD/lcd.h"

#define  LED_RED OCR3C
#define  LED_GREEN OCR3A
#define  LED_BLUE OCR3B

volatile static int loadmenu = 0;
volatile static int menustep = 0;
volatile static int keypressint;
volatile static int R;


void menu(char decodedChar)
{
	char buffer[7];
	///Sends the menu screen to the display first time the menu is loaded
	if (loadmenu == 0){
		lcd_clrscr();
		lcd_puts("Menu:");
		lcd_gotoxy(0,1);
		lcd_puts("8=Next    9=Back");
		loadmenu = 1;
	}
	switch (decodedChar){
		case '1':
		keypressint = 1;
		break;
		case '2':
		keypressint = 2;
		break;
		case '3':
		keypressint = 3;
		break;
		case '4':
		keypressint = 4;
		break;
		case '5':
		keypressint = 5;
		break;
		case '6':
		keypressint = 6;
		break;
		case '7':
		keypressint = 7;
		break;
		
		///Every time 8 is pressed while in menu increasing menustep to show different text on every keypress
		case '8':
		keypressint = 8;
		if (menustep == 0){
			lcd_clrscr();
			lcd_puts("Press A To");
			lcd_gotoxy(0,1);
			lcd_puts("Set Temperature");
			menustep++;
		}
		else if (menustep == 1){
			lcd_clrscr();
			lcd_puts("Press B To");
			lcd_gotoxy(0,1);
			lcd_puts("Set Fan Speed");
			menustep++;
		}
		else if (menustep == 2){
			lcd_clrscr();
			lcd_puts("Press C To");
			lcd_gotoxy(0,1);
			lcd_puts("Change RGB Color");
			menustep++;
		}
		else if (menustep == 3){
			lcd_clrscr();
			lcd_puts("Press D To");
			lcd_gotoxy(0,1);
			lcd_puts("Get to Main Menu");
			menustep++;
		}
		///Resets to the main menu start screen
		else if (menustep == 4){
			menustep = 0;
			loadmenu = 0;
		}
		break;
		
		case '9':
		keypressint = 9;
		if (menustep == 1){
			lcd_clrscr();
			lcd_puts("Press A To");
			lcd_gotoxy(0,1);
			lcd_puts("Set Temperature");
			menustep--;
		}
		else if (menustep == 2){
			lcd_clrscr();
			lcd_puts("Press B To");
			lcd_gotoxy(0,1);
			lcd_puts("Set Fan Speed");
			menustep--;
		}
		else if (menustep == 3){
			lcd_clrscr();
			lcd_puts("Press C To");
			lcd_gotoxy(0,1);
			lcd_puts("Change RGB Color");
			menustep--;
		}
		else if (menustep == 4){
			lcd_clrscr();
			lcd_puts("Press D To");
			lcd_gotoxy(0,1);
			lcd_puts("Get to Main Menu");
			menustep--;
		}
		else if (menustep == 0){
			menustep = 4;
			loadmenu = 0;
		}
		break;
		
		case 'A':
		menustep = 10;
		break;
		
		case 'B':
		menustep = 20;
		break;
		
		case 'C':
		lcd_clrscr();
		lcd_puts("Enter Red Value");
		lcd_gotoxy(0,1);
		lcd_puts("1-255");
		menustep = 30;
		
		break;
		
		case 'D':
		menustep = 0;
		loadmenu = 0;
		break;
		
		///Creates an integer from the keyspressed
		case '*':
		if (menustep = 30){
			R = (R*10) + keypressint;
			lcd_clrscr();
			itoa(R,buffer,10);
			lcd_puts(buffer);
		}
		break;
		
		///Passes the integer to the Red LED Port
		case '#':
		if (menustep = 30){
			LED_RED = R;
			R = 0;
			keypressint = 0;
			menustep = 0;
			loadmenu = 0;
		}
		break;
	}
}