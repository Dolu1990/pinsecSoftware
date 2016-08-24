#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <TestCom.h>
#include <Uart.h>

#define GPIO_CTRL_BASE ((volatile uint32_t*)(0xF0000000))
#define UART_CTRL_BASE ((volatile uint32_t*)(0xF0010000))

UartCtrl uartCtrl = UartCtrl(UART_CTRL_BASE);

uint32_t phase = 42;


#ifdef __cplusplus
extern "C" {
#endif

void writeChars(char* value);


extern void main2();

int main() {
	uartCtrl.setClockDivider(50000000 / 115200 / 8);
	uartCtrl.setFrameConfig(8,NONE,TWO);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);

	char *yolo = (char*)malloc (100);
	sprintf(yolo,"miaou %d %f",42,3.14f);

	writeChars(yolo);

	putchar('X');

	writeChars(" Bonjour ");

	printf("choubaka\n");
	printf("yolo %d %f\n",42,3.14f);
	writeChars(" Bonjour ");

	main2();
	while(1){
		/*uartCtrl.write('5');
		uartCtrl.write('6');
		uartCtrl.write('7');
		uartCtrl.write('\r');
		uartCtrl.write('\n');*/

	}
}


void irqCpp(uint32_t irq){
	phase += 1;
}

int     times (){
 return 0;
}
#include <time.h>
clock_t	clock(){
  return times();
}

int close(int fd) {
	return 0;
}

int fstat(int fd, struct _stat *buffer) {
	return 0;
}

int isatty(int fd) {
	return 0;
}

long lseek(int fd, long offset, int origin) {
	return 0;
}

int read(int fd, void *buffer, unsigned int count) {
	return 0;
}


void writeChar(char value) {
	uartCtrl.write(value);
}

void writeChars(char* value) {
	while (*value) {
		writeChar(*(value++));
	}
}

int write(int fd, const void *buffer, unsigned int count) {
	for (int idx = 0; idx < count; idx++) {
		writeChar(((char*) buffer)[idx]);
	}
	return count;
}

#ifdef __cplusplus
}
#endif



