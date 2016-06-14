#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <Uart.h>

#define UART_CTRL_BASE ((volatile uint32_t*)(0xF0010000))

int main() {
	UartCtrl uartCtrl = UartCtrl(UART_CTRL_BASE);
	uartCtrl.setClockDivider(4);
	uartCtrl.setFrameConfig(8,NONE,ONE);

	uartCtrl.write(0x55);
	uartCtrl.write(0x00);
}




