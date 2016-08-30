#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <TestCom.h>
#include <Uart.h>
#include <Vga.h>
#include <Pinsec.h>

UartCtrl uartCtrl = UartCtrl(UART_BASE);


#ifdef __cplusplus
extern "C" {
#endif

#define RES_X 48
#define RES_Y 32

__attribute__ ((section (".noinit"))) __attribute__ ((aligned (4*8))) uint16_t vgaFramebuffer[RES_Y][RES_X];

int main() {
	uartCtrl.setClockDivider(CORE_HZ / 115200 / UART_SAMPLE_PER_BAUD);
	uartCtrl.setFrameConfig(8,NONE,TWO);
	uartCtrl.setReadInterruptEnable(0);
	uartCtrl.setWriteInterruptEnable(0);

	/*for(uint32_t y = 0;y < RES_Y;y++){
		for(uint32_t x = 0;x < RES_X;x++){
			vgaFramebuffer[y][x] = (x & 0x1F) + ((y & 0x3F) << 5);
		}
	}*/
	for(uint32_t idx = 0;idx < RES_X*RES_Y;idx++){
		vgaFramebuffer[0][idx] = idx;
	}

	VgaCtrl vgaCtrl = VgaCtrl(VGA_BASE);
    vgaCtrl.stop();
	vgaCtrl.setTimings(vga_simRes);  // vga_simRes   vga_h640_v480_r60
	vgaCtrl.setFrameSize(RES_X*RES_Y*2);
	vgaCtrl.setFrameBase((uint32_t)vgaFramebuffer);
    vgaCtrl.run();


    while(1){
        for(uint32_t idx = 0;idx < 6000;idx++){
        	asm("nop");
        }

        vgaCtrl.stop();
    	vgaCtrl.setTimings(vga_simRes);  // vga_simRes   vga_h640_v480_r60
    	vgaCtrl.setFrameSize(RES_X*RES_Y*2);
    	vgaCtrl.setFrameBase((uint32_t)vgaFramebuffer);
        vgaCtrl.run();

    }

}


void irqCpp(uint32_t irq){

}

#ifdef __cplusplus
}
#endif



