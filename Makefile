MMC = atmega328p
F_CPU = 1000000L

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os -c
CPPFLAGS = -D F_CPU=$(F_CPU)
INCLUDES = -Iinclude

lib/liblcd.a: obj/lcd_basic.o obj/lcd_read.o obj/lcd_puts.o
	avr-ar rcs $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $< -o $@

