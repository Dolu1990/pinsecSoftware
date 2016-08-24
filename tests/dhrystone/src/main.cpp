#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <TestCom.h>
#include <Uart.h>
#include <UartStdio.h>
#include <Pinsec.h>
#include <Timer.h>


UartCtrl uartCtrl = UartCtrl(UART_BASE);
UartCtrl *uartStdio = &uartCtrl;

TimerCtrl timerA = TimerCtrl(TIMER_A_BASE);

#ifdef __cplusplus
extern "C" {
#endif

extern void main2();

int main() {
	timerA.setLimit(0xFFFFFFFF);
	timerA.setEnables(0x00010001);
	uartCtrl.setClockDivider(CORE_HZ / 115200 / UART_SAMPLE_PER_BAUD);
	uartCtrl.setFrameConfig(8,NONE,TWO);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);

	main2();
}


void irqCpp(uint32_t irq){

}


int     times (){
  int value = timerA.getValue();
  return value;
}
#include <time.h>
clock_t	clock(){
  return times();
}

#ifdef __cplusplus
}
#endif



