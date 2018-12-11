#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "lcd.h"

int main(void) {
	lcd_io_init();
	lcd_init();
	lcd_puts("Hello\nWorld");
	while(1) {
	}
	return 1;
}
