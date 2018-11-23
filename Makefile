NAME = lcd.c 

MMC = atmega328p
F_CPU = 1000000L

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os -c
CPPFLAGS = -D F_CPU=$(F_CPU)

compile: liblcd.a

liblcd.a: lcd.o
	avr-ar rcs $@ $<

lcd.o: lcd.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< 

