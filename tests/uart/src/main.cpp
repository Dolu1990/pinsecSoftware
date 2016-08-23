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


int main() {

	uartCtrl.setClockDivider(4);
	uartCtrl.setFrameConfig(8,NONE,ONE);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);




	testCom::writeValue(uartCtrl.writeAvailability());
	uartCtrl.write(0xAA);
	uartCtrl.write(0x01);
	uartCtrl.write(0x02);
	uartCtrl.write(0x03);
	uint32_t sum = 0;

	while(uartCtrl.readOccupancy() != 4);
	testCom::writeValue(uartCtrl.writeAvailability());

	testCom::writeValue(uartCtrl.read());
	testCom::writeValue(uartCtrl.readOccupancy());
	testCom::writeValue(uartCtrl.read());
	testCom::writeValue(uartCtrl.read());
	testCom::writeValue(uartCtrl.read());
	testCom::writeValue(uartCtrl.readOccupancy());

	uartCtrl.setReadInterruptEnable(1);
	uartCtrl.write(0x99);
	while(phase != 1);
	testCom::writeValue(0x12345678);

	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.write(0x9A);
	testCom::writeValue(uartCtrl.read());

	uartCtrl.setReadInterruptEnable(1);
	uartCtrl.write(0x9B);
	while(phase != 2);
	testCom::writeValue(0x1234567B);
}


void irqCpp(uint32_t irq){
	testCom::writeValue(irq);
	testCom::writeValue(uartCtrl.read());
	phase += 1;
}

#ifdef __cplusplus
}
#endif



