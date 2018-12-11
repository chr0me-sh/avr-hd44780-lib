#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void lcd_io_init(void) { /* Need to remake this so it can be used in any pin setup */
	DATA_DDR |= ((1<<DB4)|(1<<DB5)|(1<<DB6)|(1<<DB7));
	RS_DDR   |= (1<<RS);
	RW_DDR   |= (1<<RW);
	E_DDR    |= (1<<E);
}
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

	DATA_PORT = ((data>>4) & 0x0F);
	lcd_epulse();

	DATA_PORT = (data & 0x0F);
	lcd_epulse();
}

void lcd_newline(void) {
	if(lcd_read() > 0x40) lcd_cmd(LCD_HOME); /* If on line 2, move line 1, if on line 2, go home */
	else lcd_cmd(LCD_LINE_2);
}

void lcd_putc(char c) {
	if(c == '\n' || c == '\r') { /* Goes to the other line when recieving a newline or car. return */
		lcd_newline();           /* carriage return is included due to terminal behaviour          */
	} else {                     /* may need to be changed later...                                */
		lcd_char(c);
	}
}

void lcd_init(void) {
	_delay_ms(120);        /* Power on delay */

	DATA_PORT = 0x03;       /* Function set */
	lcd_epulse();
	_delay_ms(6);

	lcd_epulse();
	_delay_ms(2);

	lcd_epulse();
	_delay_ms(2);

	DATA_PORT = 0x02;       /* Set to 4-bit */
	lcd_epulse();
	_delay_ms(2);

	lcd_cmd(0x28);         /* Set 2-line display */
	lcd_cmd(0x08);         /* Display off */

	lcd_cmd(LCD_CLEAR);
	_delay_ms(2);

	lcd_cmd(0x06);        /* Entry mode set (increment) */
	lcd_cmd(0x0C);        /* Display on, no cursor */
}
