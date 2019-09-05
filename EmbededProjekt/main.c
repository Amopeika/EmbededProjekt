/**
*	Titel: main.c
*
*	Author: Kevin Pike Darmer
*
*	main method
*
*	ColumnScan() sets the collumns to low one by one
*	ReadRows() reads if a button is pressed for each row one by one
*	DecodeKeyboard() decodes what char was pressed by looking up collumn and row number in multidimensional array
*	menu() shows the menu and send the parameters to change in case of button press
* 
*/
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