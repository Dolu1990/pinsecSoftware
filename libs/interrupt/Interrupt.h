/*
 * InterruptCtrl.h
 *
 *  Created on: Aug 24, 2016
 *      Author: clp
 */

#ifndef INTERRUPTCTRL_H_
#define INTERRUPTCTRL_H_

#include <stdint.h>


class InterruptCtrl{
public:
	InterruptCtrl(volatile uint32_t *base){
		this->base = base;
		setMasks(0);
		clearPendings(0xFFFFFFFF);
	}

	void clearPendings(uint32_t value) {
		base[0] = value;
	}

	uint32_t getPendings() {
		return base[0];
	}

	void setMasks(uint32_t value) {
		base[1] = value;
	}

	uint32_t getMasks() {
		return base[1];
	}

	volatile uint32_t* base;
};



#endif /* INTERRUPTCTRL_H_ */
