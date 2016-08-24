#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include <TestCom.h>
#include <Pinsec.h>
#include <Timer.h>
#include <Prescaler.h>
#include <Interrupt.h>



#ifdef __cplusplus
extern "C" {
#endif

InterruptCtrl interrupt = InterruptCtrl(TIMER_INTERRUPT_BASE);
PrescalerCtrl prescaler = PrescalerCtrl(TIMER_PRESCALER_BASE);
TimerCtrl timerA = TimerCtrl(TIMER_A_BASE);
TimerCtrl timerB = TimerCtrl(TIMER_B_BASE);
TimerCtrl timerC = TimerCtrl(TIMER_C_BASE);
TimerCtrl timerD = TimerCtrl(TIMER_D_BASE);


int main() {
	prescaler.setLimit(7);

	timerA.setLimit(12);
	timerA.setEnables(0x00000001);

	timerB.setLimit(10);
	timerB.setEnables(0x00000002);

	timerC.setLimit(8);
	timerC.setEnables(0x00010002);

	interrupt.clearPendings(0xF);
	interrupt.setMasks(0x2);

}


void irqCpp(uint32_t irq){
	if(irq == 0x20){
		uint32_t pendings = interrupt.getPendings();
		if(pendings & 0x2){
			timerB.clearValue();
			interrupt.clearPendings(0x2);
		}
	}
}



#ifdef __cplusplus
}
#endif



