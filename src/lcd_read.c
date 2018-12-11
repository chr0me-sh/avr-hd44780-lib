#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int lcd_read(void) {
	DATA_DDR = ((0<<DB4)|(0<<DB5)|(0<<DB6)|(0<<DB7));
	lcd_rw_on();

	uint8_t reg;

	lcd_e_on();
	lcd_e_delay();
	reg = ((DATA_PIN) << 4);
	lcd_e_off();

	lcd_e_delay();

	lcd_e_on();
	lcd_e_delay();
	reg |= (DATA_PIN & 0x0F);
	lcd_e_off();

	lcd_rw_off();
	DATA_DDR = 0xFF;
	return reg;
}
