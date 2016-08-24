/*
 * UartCtrl.h
 *
 *  Created on: Jun 14, 2016
 *      Author: clp
 */

#ifndef TIMERCTRL_H_
#define TIMERCTRL_H_

#include <stdint.h>


class TimerCtrl{
public:
	TimerCtrl(volatile uint32_t *base){
		this->base = base;
		setEnables(0);
		clearValue();
	}

	void setEnables(uint32_t value) {
		base[0] = value;
	}

	uint32_t getEnables() {
		return base[0];
	}


	void setLimit(uint32_t value) {
		base[1] = value;
	}

	uint32_t getLimit() {
		return base[1];
	}

	void clearValue() {
		base[2] = 0;
	}

	uint32_t getValue() {
		return base[2];
	}

	volatile uint32_t* base;
};


#endif /* TIMERCTRL_H_ */
