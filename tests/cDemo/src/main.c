#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define CORE_HZ 100000000

#define GPIO_A_BASE    ((volatile uint32_t*)(0xF0000000))
#define GPIO_B_BASE    ((volatile uint32_t*)(0xF0001000))
#define UART_BASE      ((volatile uint32_t*)(0xF0010000))
#define VGA_BASE       ((volatile uint32_t*)(0xF0030000))

#define TIMER_PRESCALER_BASE   ((volatile uint32_t*)(0xF0020000))
#define TIMER_INTERRUPT_BASE   ((volatile uint32_t*)(0xF0020010))
#define TIMER_A_BASE   ((volatile uint32_t*)(0xF0020040))
#define TIMER_B_BASE   ((volatile uint32_t*)(0xF0020050))
#define TIMER_C_BASE   ((volatile uint32_t*)(0xF0020060))
#define TIMER_D_BASE   ((volatile uint32_t*)(0xF0020070))


void initUart(){
	//Enable RX interrupts
	UART_BASE[1] = 2;
	//Set clock divider
	UART_BASE[2] = CORE_HZ / 115200 / 8;
	//Set 8 bits per frame, no parity, one stop bit
	UART_BASE[3] = 7;
}

void initTimer(){
	//Set the prescaler to tick at 10 KHz
	TIMER_PRESCALER_BASE[0] = CORE_HZ/10000-1;

	//Set the timerA to count up each the prescaler tick, and enable the auto-restart
	TIMER_A_BASE[0] = 0x00010002;
	//Set the timerA to tick at 0.5 Hz
	TIMER_A_BASE[1] = 10000*2;

	//Set the timerB to count up each the prescaler tick, and enable the auto-restart
	TIMER_B_BASE[0] = 0x00010002;
	//Set the timerB to tick at 4 Hz
	TIMER_B_BASE[1] = 10000/4;

	//Clear all pendings interrupts
	TIMER_INTERRUPT_BASE[0] = 0xF;
	//Enable timer A and B interrupt
	TIMER_INTERRUPT_BASE[1] = 0x3;
}

void initGpio(){
	//Set leds to zero
	GPIO_A_BASE[0] = 0;
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
		uint32_t pendings = TIMER_INTERRUPT_BASE[0];
		if(pendings & 0x1){  //TimerA ?
			printf("TimerB tick\n");
			TIMER_INTERRUPT_BASE[0] = 0x1;
		}
		if(pendings & 0x2){  //TimerB ?
			TIMER_INTERRUPT_BASE[0] = 0x2;
			GPIO_A_BASE[0] = GPIO_A_BASE[1] + 1;
		}
	}
	if(irq & 0x10){  //UART interrupt ?
		uint32_t rx = UART_BASE[0];
		if(rx & 0x00010000){
			TIMER_A_BASE[2] = 0;
			UART_BASE[0] = rx & 0xFF;
		}
	}
}



//Implement stdio functions to redirect the printf to the uart.
int close(int fd) {return 0;}
int fstat(int fd, struct _stat *buffer) {return 0;}
int isatty(int fd) {return 0;}
long lseek(int fd, long offset, int origin) {return 0;}
int read(int fd, void *buffer, unsigned int count) {return 0;}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		while(((UART_BASE[1] >> 16) & 0xFF) == 0);
		UART_BASE[0] = ((char*) buffer)[idx];
	}
	return count;
}




