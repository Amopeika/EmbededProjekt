/**
*	Titel: init.c
*
*	Author: Kevin Pike Darmer
*
*	Initialisation
*
*
*/
#include <avr/io.h>
#include "../LCD/lcd.h"

void init(void)
{
	UartInit();
	lcd_init(LCD_DISP_ON);
	PORTC |= (1<<PC4) | (1<<PC5) | (1<<PC6) | (1<<PC7);									//Set PC4 PC5 PC6 PC7 as Pull-UP
	DDRC |= 0x0F;																		//Set PC0 PC1 PC2 PC3 to Output
	TCCR3A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1C1);
	TCCR3A |= (1<<WGM10) | (1<<WGM11);
	TCCR3B |= (1<<CS01) | (1<<CS00);
	DDRE |= (1<<PE3) | (1<<PE4) | (1<<PE5);
}