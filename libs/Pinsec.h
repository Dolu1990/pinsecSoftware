/*
 * Mapping.h
 *
 *  Created on: Aug 24, 2016
 *      Author: clp
 */

#ifndef MAPPING_H_
#define MAPPING_H_

#ifdef CONFIG_CORE_HZ
#define CORE_HZ CONFIG_CORE_HZ
#else
#define CORE_HZ 100000000
#endif

#define GPIO_A_BASE    ((volatile uint32_t*)(0xF0000000))
#define GPIO_B_BASE    ((volatile uint32_t*)(0xF0001000))
#define UART_BASE      ((volatile uint32_t*)(0xF0010000))
#define VGA_BASE       ((volatile uint32_t*)(0xF0030000))

#define TIMER_PRESCALER_BASE   ((volatile uint32_t*)(0xF0020000))
#define TIMER_INTERRUPT_BASE   ((volatile uint32_t*)(0xF0020010))
#define TIMER_A_BASE   ((volatile uint32_t*)(0xF0020040))
#define TIMER_B_BASE   ((volatile uint32_t*)(0xF0020050))
#define TIMER_C_BASE   ((volatile uint32_t*)(0xF0020060))
#define TIMER_D_BASE   ((volatile uint32_t*)(0xF0020070))

#define TEST_COM_BASE ((volatile uint32_t*)(0xF00FFF00))


#define UART_SAMPLE_PER_BAUD 8


#endif /* MAPPING_H_ */
