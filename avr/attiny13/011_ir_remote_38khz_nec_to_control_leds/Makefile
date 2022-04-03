#=========================================
#	Edit by 4eburashk http://csn.net4me.net
#		On Sun 18 Jul 2021 02:27:35 PM MSK
#=========================================

MCU=attiny13
FUSE_L=0x7A
FUSE_H=0xFF
F_CPU=9600000
CC=avr-gcc
LD=avr-ld
OBJCOPY=avr-objcopy
SIZE=avr-size
AVRDUDE=avrdude -v -C/etc/avrdude.conf
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main
SRCS = main.c
	
all:
	${CC} ${CFLAGS} -o ${TARGET}.o ${SRCS}
	${LD} -o ${TARGET}.elf ${TARGET}.o
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex	
	${SIZE} --mcu=${MCU} ${TARGET}.elf

flash:
	${AVRDUDE} -p ${MCU} -c usbasp -B32 -U flash:w:${TARGET}.hex:i -F -P usb 

fuse:
	$(AVRDUDE) -p ${MCU} -c usbasp -B32 -U hfuse:w:${FUSE_H}:m -U lfuse:w:${FUSE_L}:m
	
clean:
	rm -f *.c~ *.o *.elf *.hex

# END
