MMC = atmega328p
F_CPU = 1000000L

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os -c
CPPFLAGS = -D F_CPU=$(F_CPU)
INCLUDES = -Iinclude

OBJ = lcd_basic.o lcd_read.o
SRC = $(OBJ:.o=.c)

lib/liblcd.a: obj/lcd_basic.o obj/lcd_read.o
	avr-ar rcs $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $< -o $@

