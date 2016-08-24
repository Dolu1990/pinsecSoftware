/*
 * UartCtrl.h
 *
 *  Created on: Jun 14, 2016
 *      Author: clp
 */

#ifndef PRESCALERCTRL_H_
#define PRESCALERCTRL_H_

#include <stdint.h>


class PrescalerCtrl{
public:
	PrescalerCtrl(volatile uint32_t *base){
		this->base = base;
	}

	void setLimit(uint32_t value) {
		base[0] = value;
	}

	uint32_t getLimit() {
		return base[0];
	}

	volatile uint32_t* base;
};


#endif /* PRESCALERCTRL_H_ */
