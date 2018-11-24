#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void lcd_puts(char* s) {
	for(int i=0; s[i]; i++) {
		lcd_putc(s[i]);
	}
}
