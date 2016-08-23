#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <TestCom.h>
#include <Uart.h>

#define GPIO_CTRL_BASE ((volatile uint32_t*)(0xF0000000))
#define UART_CTRL_BASE ((volatile uint32_t*)(0xF0010000))

UartCtrl uartCtrl = UartCtrl(UART_CTRL_BASE);

volatile uint32_t phase = 0;


#ifdef __cplusplus
extern "C" {
#endif

void writeChars(char* value);

int main() {
	uartCtrl.setClockDivider(50000000 / 115200 / 8);
	uartCtrl.setFrameConfig(8,NONE,TWO);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);
	writeChars(" Bonjour ");
	printf("choubaka");
	printf("yolo %d %f",42,3.14f);
	/*writeChars(" Bonjour ");
	while(1){
		uartCtrl.write('5');
		uartCtrl.write('6');
		uartCtrl.write('7');
		uartCtrl.write('\r');
		uartCtrl.write('\n');

	}*/
}


void irqCpp(uint32_t irq){
	testCom::writeValue(irq);
	testCom::writeValue(uartCtrl.read());
	phase += 1;
}




#ifdef __cplusplus
}
#endif



