#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <TestCom.h>



#ifdef __cplusplus
extern "C" {
#endif
class ClassA{
public:
	ClassA(){
		number1 = 0x8899AABB;
		number2 = 0xCCDDEEFF;
	}
	uint32_t number1,number2;
};
volatile uint32_t zero1 = 0;
volatile uint32_t zero2 = 0;
volatile uint32_t number1 = 0x11223344;
volatile uint32_t number2 = 0x44556677;

ClassA a = ClassA();

int main() {
	testCom::writeValue(zero1);
	testCom::writeValue(zero2);
	testCom::writeValue(number1);
	testCom::writeValue(number2);
	testCom::writeValue(a.number1);
	testCom::writeValue(a.number2);
}


void irqCpp(uint32_t irq){

}

#ifdef __cplusplus
}
#endif



