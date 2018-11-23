#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "lcd.h"

int main(void) {
	DDRC = ((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7)|(1<<RS)|(1<<RW));
	DDRB = (1<<E);
	lcd_init();
	lcd_putc('L');
	while(1) {
	}
	return 1;
}
