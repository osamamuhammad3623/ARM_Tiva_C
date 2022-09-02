#include "basic_timer.h"
#include <stdint.h>
#include "common_macros.h"
#include "tm4c123gh6pm.h"


/* Global pointers to call-back functions of Timer0 & Timer1 (both channels) */
static void volatile (*g_Timer0ACallBackPtr)(void) = 0;
static void volatile (*g_Timer0BCallBackPtr)(void) = 0;
static void volatile (*g_Timer1ACallBackPtr)(void) = 0;
static void volatile (*g_Timer1BCallBackPtr)(void) = 0;
/* pointer to call-back function of Timer2 */
static void volatile (*g_Timer2CallBackPtr)(void) = 0;


void Timer_init(const Timer_configuration *timer_config) {

	SET_BIT(SYSCTL_RCGCTIMER_R, timer_config->timer_ID); /* enable clock for timer*/
	SET_BIT(SYSCTL_RCGCGPIO_R, 1); /* enable clock for port B */

	if (timer_config->timer_ID == Timer0) {

		/* set alternate function [from table]*/
		if (timer_config->channel == Channel_A){
			CLEAR_BIT(TIMER0_CTL_R, 0); /* disable timer0A */
			TIMER0_CFG_R = 0x4; /* configure the timer to work in individual mode (channel A and B) */
			SET_BIT(GPIO_PORTB_AFSEL_R, 6); // enable alternate function on pin6  
			GPIO_PORTB_PCTL_R |= (7<<24); // timer 0A on pin6
			TIMER0_TAMR_R = timer_config->mode; /* set timer mode */

			/* set the timer to count up/down */
			if (timer_config->dir == Count_down) {
				CLEAR_BIT(TIMER0_TAMR_R, TIMER_TAMR_TACDIR);
			} else {
				SET_BIT(TIMER0_TAMR_R, TIMER_TAMR_TACDIR);
			}
			TIMER0_TAPR_R = (timer_config->clocks_per_tick) -1;
			SET_BIT(NVIC_EN0_R ,19); /* enable timer 0-A interrupt in NVIC table */
			TIMER0_TAILR_R = timer_config->compareValue; /* set compare value */
			SET_BIT(TIMER0_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
			g_Timer0ACallBackPtr = timer_config->callBack; /* set the call-back function */


		} if (timer_config->channel == Channel_B){
			CLEAR_BIT(TIMER0_CTL_R, 8); /* disable timer0B */
			TIMER0_CFG_R = 0x4; /* configure the timer to work in individual mode (channel A and B) */
			SET_BIT(GPIO_PORTB_AFSEL_R, 7); // enable alternate function on pin7 
			GPIO_PORTB_PCTL_R |= (7<<28); // timer 0B on pin7
			TIMER0_TBMR_R = timer_config->mode; /* set timer mode */

			/* set the timer to count up/down */
			if (timer_config->dir == Count_down) {
				CLEAR_BIT(TIMER0_TBMR_R, TIMER_TBMR_TBCDIR);
			} else {
				SET_BIT(TIMER0_TBMR_R, TIMER_TBMR_TBCDIR);
			}
			TIMER0_TBPR_R = (timer_config->clocks_per_tick) -1;
			SET_BIT(NVIC_EN0_R ,20); /* enable timer 0-B interrupt in NVIC table */
			TIMER0_TBILR_R = timer_config->compareValue; /* set compare value */
			SET_BIT(TIMER0_IMR_R, 8);/* Timer 0B Time-Out Interrupt Mask */
			g_Timer0BCallBackPtr = timer_config->callBack; /* set the call-back function */
		}


	} else if (timer_config->timer_ID == Timer1) {

		/* set alternate function [from table]*/
		if (timer_config->channel == Channel_A){
			CLEAR_BIT(TIMER1_CTL_R, 0); /* disable timer1A */
			TIMER1_CFG_R = 0x4; /* configure the timer to work in individual mode (channel A and B) */
			SET_BIT(GPIO_PORTB_AFSEL_R, 4); // enable alternate function on pin4  
			GPIO_PORTB_PCTL_R |= (7<<16); // timer 1A on pin4
			TIMER1_TAMR_R = timer_config->mode; /* set timer mode */

			/* set the timer to count up/down */
			if (timer_config->dir == Count_down) {
				CLEAR_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
			} else {
				SET_BIT(TIMER1_TAMR_R, TIMER_TAMR_TACDIR);
			}
			TIMER1_TAPR_R = (timer_config->clocks_per_tick) -1;
			SET_BIT(NVIC_EN0_R ,21); /* enable timer 1-A interrupt in NVIC table */
			TIMER1_TAILR_R = timer_config->compareValue; /* set compare value */
			SET_BIT(TIMER1_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
			g_Timer1ACallBackPtr = timer_config->callBack; /* set the call-back function */


		}else if (timer_config->channel == Channel_B){
			CLEAR_BIT(TIMER1_CTL_R, 8); /* disable timer1B */
			TIMER1_CFG_R = 0x4; /* configure the timer to work in individual mode (channel A and B) */
			SET_BIT(GPIO_PORTB_AFSEL_R, 5); // enable alternate function on pin5
			GPIO_PORTB_PCTL_R |= (7<<20); // timer 1B on pin5
			TIMER1_TBMR_R = timer_config->mode; /* set timer mode */

			/* set the timer to count up/down */
			if (timer_config->dir == Count_down) {
				CLEAR_BIT(TIMER1_TBMR_R, TIMER_TBMR_TBCDIR);
			} else {
				SET_BIT(TIMER1_TBMR_R, TIMER_TBMR_TBCDIR);
			}
			TIMER1_TBPR_R = (timer_config->clocks_per_tick) -1;
			SET_BIT(NVIC_EN0_R ,22); /* enable timer 0-B interrupt in NVIC table */
			TIMER1_TBILR_R = timer_config->compareValue; /* set compare value */
			SET_BIT(TIMER1_IMR_R, 8);/* Timer 0B Time-Out Interrupt Mask */
			g_Timer1BCallBackPtr = timer_config->callBack; /* set the call-back function */
		}
	
	} else if (timer_config->timer_ID == Timer2) {
		/* when configuring the timer as 32-bit timer, we use timer A only for control */
		CLEAR_BIT(TIMER2_CTL_R, 0); /* disable timer1A */
		TIMER2_CFG_R = 0; /* configure the timer to work in 32-bit mode (no channels) */
		SET_BIT(GPIO_PORTB_AFSEL_R, 6); // enable alternate function on pin
		GPIO_PORTB_PCTL_R |= (7<<0); // timer 2A on pin0
		TIMER2_TAMR_R = timer_config->mode; /* set timer mode */

		/* set the timer to count up/down */
		if (timer_config->dir == Count_down) {
			CLEAR_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		} else {
			SET_BIT(TIMER2_TAMR_R, TIMER_TAMR_TACDIR);
		}
		SET_BIT(NVIC_EN0_R ,23); /* enable timer 2-A interrupt in NVIC table */
		TIMER2_TAILR_R = timer_config->compareValue; /* set compare value */
		SET_BIT(TIMER2_IMR_R, 0);/* Timer A Time-Out Interrupt Mask */
		g_Timer2CallBackPtr = timer_config->callBack; /* set the call-back function */
	}
}

void Timer_start(Timer_ID timer_id, Timer_Channel channel){
	if (timer_id == Timer0 ){
		switch (channel)
		{
		case Channel_A:
			SET_BIT(TIMER0_CTL_R, 0);
			break;
		
		case Channel_B:
			SET_BIT(TIMER0_CTL_R, 8);
			break;
		}
	
	}else if (timer_id == Timer1 ){
		switch (channel)
		{
		case Channel_A:
			SET_BIT(TIMER1_CTL_R, 0);
			break;
		
		case Channel_B:
			SET_BIT(TIMER1_CTL_R, 8);
			break;
		}

	} else if (timer_id == Timer2 ){
		SET_BIT(TIMER2_CTL_R, 0);
	}
}

void Timer_stop(Timer_ID timer_id, Timer_Channel channel){
	if (timer_id == Timer0 ){
		switch (channel)
		{
		case Channel_A:
			CLEAR_BIT(TIMER0_CTL_R, 0);
			break;
		
		case Channel_B:
			CLEAR_BIT(TIMER0_CTL_R, 8);
			break;
		}
	
	}else if (timer_id == Timer1 ){
		switch (channel)
		{
		case Channel_A:
			CLEAR_BIT(TIMER1_CTL_R, 0);
			break;
		
		case Channel_B:
			CLEAR_BIT(TIMER1_CTL_R, 8);
			break;
		}

	} else if (timer_id == Timer2 ){
		CLEAR_BIT(TIMER2_CTL_R, 0);
	}
}



/* Timer 0A handler */
void TIMER0A_Handler(void){
	if (g_Timer0ACallBackPtr != 0){
		(*g_Timer0ACallBackPtr)();
		SET_BIT(TIMER0_ICR_R, 0); /* clear the count flag */
	}
}

/* Timer 0B handler */
void TIMER0B_Handler(void){
	if (g_Timer0BCallBackPtr != 0){
		(*g_Timer0BCallBackPtr)();
		SET_BIT(TIMER0_ICR_R, 8); /* clear the count flag */
	}
}

/* Timer 1A handler */
void TIMER1A_Handler(void){
	if (g_Timer1ACallBackPtr != 0){
		(*g_Timer1ACallBackPtr)();
		SET_BIT(TIMER1_ICR_R, 0);
	}
}

/* Timer 1B handler */
void TIMER1B_Handler(void){
	if (g_Timer1BCallBackPtr != 0){
		(*g_Timer1BCallBackPtr)();
		SET_BIT(TIMER1_ICR_R, 8);
	}
}

/* Timer 2A handler */
void TIMER2A_Handler(void){
	if (g_Timer2CallBackPtr != 0){
		(*g_Timer2CallBackPtr)();
		SET_BIT(TIMER2_ICR_R, 0); /* clear the count flag */
	}
}