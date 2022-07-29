#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "tm4c123gh6pm_registers.h"
#include <stdint.h>

/********************************************************/
/* Function Prototypes */
/********************************************************/

/*
Description: Initialize the SysTick timer with given value and a pointer to call-back function for the ISR
					- using system clock & interrupts 
*/
void SysTick_init(uint32_t value, void (* callBackFunction )());

/*
Description: Enable SysTick timer to start counting
*/
void SysTick_start(void);

/*
Description: Disable SysTick timer
*/
void SysTick_stop(void);

#endif /* SYS_TICK_H_ */
