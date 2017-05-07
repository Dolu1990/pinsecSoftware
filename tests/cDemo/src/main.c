#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define CORE_HZ 100000000

struct Uart{
   uint32_t readWrite;
   uint32_t status;
   uint32_t clockDivider;
   uint32_t frameConfig;
};

struct Timer{
   uint32_t ticksClears;
   uint32_t limit;
   uint32_t value;
};

struct Prescaler{
   uint32_t limit;
};

struct Gpio{
   uint32_t readWrite;
   uint32_t readOutputBuffer;
   uint32_t outputEnable;
};

struct Interrupt{
   uint32_t status;
   uint32_t mask;
};


#define gpioA          ((volatile struct Gpio*)(0xF0000000))
#define gpioB          ((volatile struct Gpio*)(0xF0001000))
#define uart           ((volatile struct Uart*)(0xF0010000))

#define timerPrescaler ((volatile struct Prescaler*)(0xF0020000))
#define timerA         ((volatile struct Timer*)(0xF0020040))
#define timerB         ((volatile struct Timer*)(0xF0020050))
#define timerC         ((volatile struct Timer*)(0xF0020060))
#define timerD         ((volatile struct Timer*)(0xF0020070))
#define timerInterrupt ((volatile struct Interrupt*)(0xF0020010))

void initUart(){
	//Enable RX interrupts
	uart->status = 2;
	//Set clock divider
	uart->clockDivider = CORE_HZ / 115200 / 8;
	//Set 8 bits per frame, no parity, one stop bit
	uart->frameConfig = 7;
}

void initTimer(){
	//Set the prescaler to tick at 10 KHz
	timerPrescaler->limit = CORE_HZ/10000-1;

	//Set the timerA to count up each the prescaler tick, and enable the auto-restart
	timerA->ticksClears = 0x00010002;
	//Set the timerA to tick at 0.5 Hz
	timerA->limit = 10000*2-1;

	//Set the timerB to count up each the prescaler tick, and enable the auto-restart
	timerB->ticksClears = 0x00010002;
	//Set the timerB to tick at 4 Hz
	timerB->limit = 10000/4-1;

	//Clear all pendings interrupts
	timerInterrupt->status = 0xF;
	//Enable timer A and B interrupt
	timerInterrupt->mask = 0x3;
}

void initGpio(){
	//Set leds as output pins
	gpioA->outputEnable = 0xFF;

	//Set leds to zero
	gpioA->readWrite = 0;
}

void setInterruptMask(uint32_t mask){
	asm("custom0 0,a0,0,2");
}


int main() {
	initUart();
	initTimer();
	initGpio();
	setInterruptMask(0xFF);

	printf("Hello world\n");
	printf("a\n");
	printf("b\n");

	while(1){
		uint64_t sum = 0;
		for(uint32_t idx = 0;idx < 10000000;idx++){
			sum += idx;
		}
		printf("Sum from 0 to 10000000 = %x%x   ref = 2d7987f0d4c0\n",(uint32_t)(sum >> 32),(uint32_t)(sum));
		if(sum != 0x2d7987f0d4c0l){
			while(1);
		}
	}
}


void irqC(uint32_t irq){
	if(irq & 0x20){  //TimerABCD interrupt ?
		uint32_t pendings = timerInterrupt->status;
		if(pendings & 0x1){  //TimerA ?
			printf("TimerB tick\n");
			timerInterrupt->status = 0x1;
		}
		if(pendings & 0x2){  //TimerB ?
			timerInterrupt->status = 0x2;
			gpioA->readWrite = gpioA->readOutputBuffer + 1;
		}
	}
	if(irq & 0x10){  //UART interrupt ?
		uint32_t rx = uart->readWrite;
		if(rx & 0x00010000){
			timerA->value = 0;
			uart->readWrite = rx & 0xFF;
		}
	}
}



//Implement stdio functions to redirect the printf to the uart.
int close(int fd) {return 0;}
int fstat(int fd, void *buffer) {return 0;}
int isatty(int fd) {return 0;}
long lseek(int fd, long offset, int origin) {return 0;}
int read(int fd, void *buffer, unsigned int count) {return 0;}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		while((uart->status & 0x00FF0000) == 0);
		uart->readWrite = ((char*) buffer)[idx];
	}
	return count;
}

int puts(const char *buffer){
   int idx;
   for (idx = 0; buffer[idx] != 0; idx++) {
	   while((uart->status & 0x00FF0000) == 0);
	   uart->readWrite = buffer[idx];
   }
   while((uart->status & 0x00FF0000) == 0);
   uart->readWrite = '\n';
   return idx;
}


