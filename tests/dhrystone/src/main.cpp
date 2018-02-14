#pragma GCC optimize ("no-inline")
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define TEST_COM_BASE ((volatile uint32_t*)(0xF00FFF00))
#include "testStdIo.h"


#ifdef __cplusplus
extern "C" {
#endif

extern void main2();

int main() {
	main2();

	TEST_COM_BASE[8] = 0;
}


void irqCpp(uint32_t irq){

}


int     times (){
  return TEST_COM_BASE[4];
}
#include <time.h>
clock_t	clock(){
  return times();
}

#ifdef __cplusplus
}
#endif



