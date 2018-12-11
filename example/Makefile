SRC = $(wildcard *.c)
NAME = $(basename $(SRC))

MMC = atmega328p
F_CPU = 16000000L
PRG = usbasp
DEV = usb

CC = avr-gcc
CFLAGS = -mmcu=$(MMC) -Wall -Os
CPPFLAGS = -D F_CPU=$(F_CPU)
LDFLAGS = -L../lib -llcd
INCLUDES = -I../include

OC = avr-objcopy
OFLAGS = -j .data -j .text -O ihex

FL = avrdude
FFLAGS = -c $(PRG) -p $(MMC) -P $(DEV) -e

.PHONY: clean flash compile all
.INTERMEDIATE: $(NAME).hex

all: flash

compile: $(NAME).hex

%.elf: %.c
	$(CC) $< $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(CPPFLAGS) -o $@

%.hex: %.elf
	$(OC) $(OFLAGS) $< $@
	
flash: $(NAME).hex
	sudo $(FL) $(FFLAGS) -U flash:w:$<:i

clean: 
	rm *.hex
