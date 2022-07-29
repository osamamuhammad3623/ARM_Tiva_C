#include "tm4c123gh6pm_registers.h"
#include <stdint.h>
#include "sys_tick.h"
#include "common_macros.h"

static void (*g_CallBackPtr)(void) = 0;

void SysTick_init(uint32_t value, void (* callBackFunction )()){
	CLEAR_BIT(SYSTICK_CTRL_REG, 0); /* disable the timer */
	SYSTICK_RELOAD_REG = value-1; /* set compare value */
	SYSTICK_CURRENT_REG = 0; /* clear current ticks */
	SET_BIT(SYSTICK_CTRL_REG, 2);  /* set clock source to System Clock */
	SET_BIT(SYSTICK_CTRL_REG, 1);  /* enable sys tick interrupt */
	SET_BIT(NVIC_EN0_REG, 15); /* enable NVIC interrupts for SysTick timer */
	g_CallBackPtr = callBackFunction; /* set the call-back function */
}

void SysTick_start(void){
	SET_BIT(SYSTICK_CTRL_REG, 0); /* enable timer [start counting] */
}

void SysTick_stop(void){
	CLEAR_BIT(SYSTICK_CTRL_REG, 0); /* disable sys tick timer */
}

void SysTick_Handler(void){
	if (g_CallBackPtr != 0){
		(*g_CallBackPtr)();
		SYSTICK_CURRENT_REG = 0; /* clear the count flag */
	}
}
