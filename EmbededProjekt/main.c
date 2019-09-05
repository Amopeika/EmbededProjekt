#include <stdio.h>
#include "stdio_setup.h"
#include "metrixKeypadLib.h"
#include "LCD/menu.h"
#include "Init/Init.h"

int main(void)
{
	init();
	unsigned char collumn;
	unsigned char row;
	unsigned char decodedChar;

	
	while(1) {
		collumn = ColumnScan();
		row = ReadRows();
		decodedChar = DecodeKeyboard(collumn,row);
		printf("%c",decodedChar);
		menu(decodedChar);
	}
}