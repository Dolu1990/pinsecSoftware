/*
 * UartCtrl.h
 *
 *  Created on: Jun 14, 2016
 *      Author: clp
 */

#ifndef UARTCTRL_H_
#define UARTCTRL_H_

#include <stdint.h>

enum UartParity {NONE = 0,EVEN = 1,ODD = 2};
enum UartStop {ONE = 0,TWO = 1};

class UartCtrl{
public:
	UartCtrl(volatile uint32_t *base){
		this->base = base;
	}

	void setClockDivider(uint32_t value){
		base[2] = value;
	}

	void setFrameConfig(uint32_t dataLength,UartParity parity,UartStop stop){
		base[3] = ((dataLength-1) << 0) | (parity << 8) | (stop << 16);
	}

	bool isWriteFull(){
		return (base[1] >> 16) == 0;
	}

	void write(uint32_t data){
		while(isWriteFull());
		base[0] = data;
	}

	uint32_t read(){
		uint32_t value;
		while(((value = base[0]) & 0xFFFF0000) == 0);
		return value;
	}

	volatile uint32_t* base;
};


#endif /* UARTCTRL_H_ */
