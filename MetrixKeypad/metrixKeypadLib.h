/**
*	Titel: metrixKeypadLib.h
*
*	Author: Kevin Pike Darmer
*
*	Keyboard Header
*
*
*/
#ifndef metrixKeypadLib_H_
#define metrixKeypadLib_H_

char ColumnScan();
char ReadRows();
char DecodeKeyboard(char collumn,char row);

#endif /* metrixKeypadLib_H_ */