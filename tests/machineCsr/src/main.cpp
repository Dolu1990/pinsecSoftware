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
	printf("Miaou !!");
	TEST_COM_BASE[8] = 0;
}


void irqCpp(uint32_t irq){

}


#ifdef __cplusplus
}
#endif



