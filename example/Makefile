SRC = $(wildcard *.c)
NAME = $(basename $(SRC))

MMC = atmega328p
F_CPU = 1000000L
PRG = usbasp
DEV = usb

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os
CPPFLAGS = -D F_CPU=$(F_CPU)

OC = avr-objcopy
OFLAGS = -j .data -j .text -O ihex

FL = avrdude
FFLAGS = -c $(PRG) -p $(MMC) -P $(DEV) -e

.PHONY: clean flash compile all

all: flash

compile: $(NAME).hex

%.elf: %.c
	$(CC) $< $(CFLAGS) -L. -llcd $(CPPFLAGS) -o $@

%.hex: %.elf
	$(OC) $(OFLAGS) $< $@
	
flash: $(NAME).hex
	sudo $(FL) $(FFLAGS) -U flash:w:$<:i

clean: 
	rm *.hex
