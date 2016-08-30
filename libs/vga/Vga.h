/*
 * VGACTRL.h
 *
 *  Created on: Jun 14, 2016
 *      Author: clp
 */

#ifndef VGACTRL_H_
#define VGACTRL_H_

#include <stdint.h>

struct VgaTiming{
	uint32_t hSyncStart ,hSyncEnd;
	uint32_t hColorStart,hColorEnd;

	uint32_t vSyncStart ,vSyncEnd;
	uint32_t vColorStart,vColorEnd;
};

class VgaCtrl{
public:
	VgaCtrl(volatile uint32_t *base){
		this->base = base;
	}

	void run(){
		base[0] = 1;
	}

	void stop(){
		base[0] = 0;
	}

	//in byte
	void setFrameSize(uint32_t frameSize){
		base[1] = frameSize-1;
	}

	void setFrameBase(uint32_t frameBase){
		base[2] = frameBase;
	}

	void setTimings(VgaTiming t){
		base[0x10 + 0] = t.hSyncStart-1;
		base[0x10 + 1] = t.hSyncEnd-1;
		base[0x10 + 2] = t.hColorStart-1;
		base[0x10 + 3] = t.hColorEnd-1;
		base[0x10 + 4] = t.vSyncStart-1;
		base[0x10 + 5] = t.vSyncEnd-1;
		base[0x10 + 6] = t.vColorStart-1;
		base[0x10 + 7] = t.vColorEnd-1;
	}

	volatile uint32_t* base;
};

const struct VgaTiming vga_h640_v480_r60 = {
    .hSyncStart  = 96,
    .hSyncEnd    = 800,
    .hColorStart = 96 + 16,
    .hColorEnd   = 800 - 48,
    .vSyncStart  = 2,
    .vSyncEnd 	 = 525,
    .vColorStart = 2 + 10,
    .vColorEnd 	 = 525 - 33
};

const struct VgaTiming vga_simRes = {
    .hSyncStart  = 8,
    .hSyncEnd    = 70,
    .hColorStart = 16,
    .hColorEnd   = 64,
    .vSyncStart  = 2,
    .vSyncEnd 	 = 48,
    .vColorStart = 8,
    .vColorEnd 	 = 40
};




#endif /* VGACTRL_H_ */
