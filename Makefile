MMC = atmega328p
F_CPU = 1000000L

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os -c
CPPFLAGS = -D F_CPU=$(F_CPU)
INCLUDES = -Iinclude

compile: lib/liblcd.a

lib/liblcd.a: obj/lcd_basic.o
	avr-ar rcs $@ $<

obj/lcd_basic.o: src/lcd_basic.c
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $< -o $@

