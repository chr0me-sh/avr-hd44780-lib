#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int lcd_read(void) {
	LCD_PORT = 0x00;
	LCD_DDR = 0xF0;
	lcd_rw_on();

	uint8_t reg;

	lcd_e_on();
	lcd_e_delay();
	reg = ((PINC) << 4);
	lcd_e_off();

	lcd_e_delay();

	lcd_e_on();
	lcd_e_delay();
	reg |= (PINC & 0x0F);
	lcd_e_off();

	LCD_PORT = 0x00;
	LCD_DDR = 0xFF;
	return reg;
}
