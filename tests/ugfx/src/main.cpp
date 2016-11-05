#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <TestCom.h>
#include <Uart.h>
#include <Vga.h>
#include <Timer.h>
#include <Pinsec.h>
#include "Bubble.h"


UartCtrl uartCtrl = UartCtrl(UART_BASE);
TimerCtrl timerA = TimerCtrl(TIMER_A_BASE);

#define RES_X 640
#define RES_Y 480

__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint16_t vgaFramebuffer[RES_Y][RES_X];

#ifdef __cplusplus
extern "C" {
#endif

int main() {
	timerA.setLimit(0xFFFFFFFF);
	timerA.setEnables(0x00010001);

	uartCtrl.setClockDivider(CORE_HZ / 115200 / UART_SAMPLE_PER_BAUD);
	uartCtrl.setFrameConfig(8,NONE,TWO);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);

	/*for(uint32_t y = 0;y < RES_Y;y++){
		for(uint32_t x = 0;x < RES_X;x++){
			vgaFramebuffer[y][x] = (x & 0x1F) + ((y & 0x3F) << 5);
		}
	}
*/
	VgaCtrl vgaCtrl = VgaCtrl(VGA_BASE);
    vgaCtrl.stop();
	vgaCtrl.setTimings(vga_h640_v480_r60);
	vgaCtrl.setFrameSize(RES_X*RES_Y*2);
	vgaCtrl.setFrameBase((uint32_t)vgaFramebuffer);
    vgaCtrl.run();

    bubble_main();

    while(1){

    }

}

int  times (){
  int value = timerA.getValue();
  return value;
}

systemticks_t gfxSystemTicks(void)
{
	return times();
}

systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
{
	return ms*50*1000;
}



void irqCpp(uint32_t irq){

}

#ifdef __cplusplus
}
#endif



