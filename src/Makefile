SRC = $(wildcard *.c)
NAME = $(basename $(SRC))

MMC = atmega328p
F_CPU = 1000000L

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os -c
CPPFLAGS = -D F_CPU=$(F_CPU)

compile: $(NAME).o

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< 

