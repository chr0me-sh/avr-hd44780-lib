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
	if(rs) lcd_rs_on();
	else lcd_rs_off();
	int cmd = LCD_PORT & 0xF0;
	LCD_PORT = cmd | ((data>>4) & 0x0F);
	lcd_epulse();
	LCD_PORT = cmd | (data & 0x0F);
	lcd_epulse();
}

int lcd_read(void) {
	int reg;
	LCD_DDR = 0xF0;
	lcd_rw_on();
	lcd_e_on();
	lcd_e_delay();
	reg = LCD_PIN << 4;
	lcd_e_off();
	lcd_e_delay();
	lcd_e_on();
	lcd_e_delay();
	reg |= LCD_PIN & 0x0F;
	lcd_e_off();
	LCD_DDR = 0xFF;
	return reg;
}

void lcd_putc(char c) {
	if(c == '\n' || c == '\r') {
		lcd_cmd(LCD_LINE_2);
	} else {
		lcd_char(c);
	}
}

void lcd_init(void) {
	lcd_cmd(0x20);
	lcd_cmd(0x28);
	lcd_cmd(0x0C);
	lcd_cmd(0x0E);
	_delay_ms(15);
	lcd_cmd(0x01);
	_delay_ms(15);
}
