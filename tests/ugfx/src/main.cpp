#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <Vga.h>
#include <Timer.h>
#include <Pinsec.h>
#include "Bubble.h"


TimerCtrl timerA = TimerCtrl(TIMER_A_BASE);

#define RES_X 640
#define RES_Y 480

#ifndef RGB332
__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint16_t vgaFramebuffer[RES_Y][RES_X];
#else
__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint8_t vgaFramebuffer[RES_Y][RES_X];
#endif

#ifdef __cplusplus
extern "C" {
#endif

int main() {
	timerA.setLimit(0xFFFFFFFF);
	timerA.setEnables(0x00010001);

	/*
	for(uint32_t y = 0;y < RES_Y;y++){
		for(uint32_t x = 0;x < RES_X;x++){
			vgaFramebuffer[y][x] = (x & 0x1F) + ((y & 0x3F) << 5);
		}
	}
	*/
	VgaCtrl vgaCtrl = VgaCtrl(VGA_BASE);
    vgaCtrl.stop();
	vgaCtrl.setTimings(vga_h640_v480_r60);
	vgaCtrl.setFrameSize(RES_X*RES_Y*sizeof(**vgaFramebuffer));
	vgaCtrl.setFrameBase((uint32_t)vgaFramebuffer);
    vgaCtrl.run();

    bubble_main();

    while(1){

    }

}

int times(void)
{
	return timerA.getValue();
}

systemticks_t gfxSystemTicks(void)
{
	return times();
}

systemticks_t gfxMillisecondsToTicks(delaytime_t ms)
{
	return ms*(CORE_HZ/1000);
}

void irqCpp(uint32_t irq)
{
}

#ifdef __cplusplus
}
#endif



