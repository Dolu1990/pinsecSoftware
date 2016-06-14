#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define APB_BASE ((volatile uint32_t*)(0xF0000000))

int main() {
	int a = 5;
	int b = 6;
	int c = 10;
	APB_BASE[2] = a+b*c;
	APB_BASE[0] = 0x01;
	APB_BASE[0] = 0x55;

	int counter = 0;
	while(1){
		APB_BASE[0] = counter;
		counter += 1;
		for(int idx = 0;idx < 1000*(APB_BASE[0] + 1);idx++){
			asm("nop");
		}
	}
	return 0;
}




