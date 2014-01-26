# make file for /home/sachin/github/avr-c

# Youtube
# Learning AVR-C
# http://www.youtube.com/watch?v=JRUSXtnjcNg&list=PLA6BB228B08B03EDD

# run as:
# make compile ARG="hello" or make ARG="hello" (to compile)
# make burn ARG="hello" (to burn)
# make clean ARG="hello" (to clean)

.PHONY: all clean compile burn

all: compile

compile:
	avr-gcc -Wall -O2 -mmcu=atmega328p -o ${ARG} ${ARG}.c
	avr-objcopy -j .text -j .data -O ihex ${ARG} ${ARG}.hex

burn:
	avrdude -C /home/sachin/Downloads/arduino-1.0.1/hardware/tools/avrdude.conf -b 115200 -P /dev/ttyUSB0 -patmega328p -carduino -D -U flash:w:${ARG}.hex:i

clean:
	-rm -rvf *.hex
	-rm -rvf *.o *~
	-rm -rvf ${ARG}
