#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void lcd_epulse(void) {
	lcd_e_on();
	lcd_e_delay();
	lcd_e_off();
}

void lcd_send(int data, int rs) {
	if(rs){
		lcd_rs_on();
	} else {
		lcd_rs_off();
	}

	int cmd = LCD_PORT & 0xF0;

	LCD_PORT = cmd | ((data>>4) & 0x0F);
	lcd_epulse();

	LCD_PORT = cmd | (data & 0x0F);
	lcd_epulse();
}

void lcd_newline(void) {
	if(lcd_read() > 0x40) lcd_cmd(0x02);
	else lcd_cmd(0xC0);
}

void lcd_putc(char c) {
	if(c == '\n' || c == '\r') {
		lcd_newline();
	} else {
		lcd_char(c);
	}
}

void lcd_init(void) {
	lcd_cmd(0x20);
	lcd_cmd(0x28);
	lcd_cmd(0x0C);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	_delay_ms(15);
}
