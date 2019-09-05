/**
*	Titel: main.c
*
*	Author: Kevin Pike Darmer
*
*	Keypad Config
*
*	Keypad Cable -- Port -- Arduino
*
*	4 -- C1 -- PC0 -- 37
*	3 -- C2 -- PC1 -- 36
*	2 -- C3 -- PC2 -- 35
*	1 -- C4 -- PC3 -- 34
*
*	5 -- R1 -- PC4 -- 33
*	6 -- R2 -- PC5 -- 32
*	7 -- R3 -- PC6 -- 31
*	8 -- R4 -- PC7 -- 30
*
*	 R1 | R2 | R3 | R4 | C1 | C2 | C3 | C4 |Char
*	  0 |	1 |  1 |  1 |  0 |	1 |	 1 |  1 |  *
*	  1 |	0 |  1 |  1 |  0 |	1 |	 1 |  1 |  7
*	  1 |	1 |  0 |  1 |  0 |	1 |	 1 |  1 |  4
*	  1 |	1 |  1 |  0 |  0 |	1 |	 1 |  1 |  1
*	  0 |	1 |  1 |  1 |  1 |	0 |	 1 |  1 |  0
*	  1 |	0 |  1 |  1 |  1 |	0 |	 1 |  1 |  8
*	  1 |	1 |  0 |  1 |  1 |	0 |	 1 |  1 |  5
*	  1 |	1 |  1 |  0 |  1 |	0 |	 1 |  1 |  2
*	  0 |	1 |  1 |  1 |  1 |	1 |	 0 |  1 |  #
*	  1 |	0 |  1 |  1 |  1 |	1 |	 0 |  1 |  9
*	  1 |	1 |  0 |  1 |  1 |	1 |	 0 |  1 |  6
*	  1 |	1 |  1 |  0 |  1 |	1 |	 0 |  1 |  3
*	  0 |	1 |  1 |  1 |  1 |	1 |	 1 |  0 |  D
*	  1 |	0 |  1 |  1 |  1 |	1 |	 1 |  0 |  C
*	  1 |	1 |  0 |  1 |  1 |	1 |	 1 |  0 |  B
*	  1 |	1 |  1 |  0 |  1 |	1 |	 1 |  0 |  A
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

char ColumnScan(){
	unsigned char bitShift[] = {0b11110111,0b11111011,0b11111101,0b11111110};
	static char i = 0;
	if (i < sizeof(bitShift)){
		PORTC = bitShift[i];
		i++;
		_delay_ms(50);
	}
	else{
		i = 0;
	}
	return i;
}

char ReadRows(){
	unsigned char rownr = 0;
	//Is row 1 low?
	if (bit_is_clear(PINC,PC4)){
		rownr = 1;
	}
	else if(bit_is_clear(PINC,PC5)){
		rownr = 2;
	}
	else if(bit_is_clear(PINC,PC6)){
		rownr = 3;
	}
	else if(bit_is_clear(PINC,PC7)){
		rownr = 4;
	}
	_delay_ms(10);
	return rownr;
}

char DecodeKeyboard(char collumn,char row)
{
	unsigned char keypad[4][5] = {{'.','*','7','4','1'},{'.','D','C','B','A'},{'.','#','9','6','3'},{'.','0','8','5','2'}};
	if(row != 0 & collumn !=4){
		return keypad[collumn][row];
	}
	else{
		return;
	}
}