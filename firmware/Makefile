CC = avr-gcc
OCP = avr-objcopy
MCU = atmega32u4
F_CPU = 16000000UL

SRC = main

$(SRC).ihex: $(SRC).elf
	$(OCP) -j .text -j .data -O ihex $(SRC).elf $(SRC).ihex

$(SRC).elf: $(SRC).o
	$(CC) -g -O2 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -o $(SRC).elf $(SRC).o

$(SRC).o: $(SRC).c
	$(CC) -g -O2 -mmcu=$(MCU) -DF_CPU=$(F_CPU) -c -o $(SRC).o $(SRC).c

flash: erase
	dfu-programmer atmega32u4 flash $(SRC).ihex

erase:
	dfu-programmer atmega32u4 erase --force
