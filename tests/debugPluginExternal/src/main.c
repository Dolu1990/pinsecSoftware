#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define PERIPH    ((volatile uint32_t*)(0x90000000))



int main() {
	uint32_t a = 1,b = 2,c = 3;
	uint32_t z;
	z = a + b + c;
	z++;
	while(1){
		z += 2;
		z += c;
		PERIPH[0] = z;
	}
}



