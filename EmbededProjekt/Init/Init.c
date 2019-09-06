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
	lcd_init(LCD_DISP_ON);																///LCD Initialisation
	PORTC |= (1<<PC4) | (1<<PC5) | (1<<PC6) | (1<<PC7);									///Set PC4 PC5 PC6 PC7 as Pull-UP
	DDRC |= 0x0F;																		///Set PC0 PC1 PC2 PC3 to Output
	TCCR3A |= (1<<COM1A1) | (1<<COM1B1) | (1<<COM1C1);									///Set the Terminal Counter Control Register to Compare Output Mode
	TCCR3A |= (1<<WGM10) | (1<<WGM11);													///Set the Terminal Counter Control Register to Waveform Generation Mode
	TCCR3B |= (1<<CS01) | (1<<CS00);													///Set the Terminal Counter Control Register Clockset
	DDRE |= (1<<PE3) | (1<<PE4) | (1<<PE5);												///Set PE3 PE4 PE5 to Output
}