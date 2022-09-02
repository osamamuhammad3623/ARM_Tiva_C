#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "basic_timer.h"
#include "led.h"
#include "switch.h"

void volatile toggle_blue(void){
	LED_Toggle(BLUE);
}

void volatile toggle_red(void){
	LED_Toggle(RED);
}

void volatile toggle_green(void){
	LED_Toggle(GREEN);
}


int main(){
	LED_Configure(BLUE);
	LED_Configure(RED);
	LED_Configure(GREEN);
	Switch_Configure(SW1);

	/* 16e6/(2^16) = 244, 
		meaning that the 16-bit mode needs to count 244 times to count a total of 16 million ticks
		that is 1 second on 16Mhz frequency */ 	
	Timer_configuration timer0b_config = {
		Timer0, 
		periodic, 
		Count_down,
		Channel_B,
		244,
		65535,
		toggle_blue
	};

	/* in one-shot mode, the timer counts only one time, so the red LED will turn on after a second
		and remains ON */
	Timer_configuration timer1b_config = {
		Timer1, 
		one_shot, 
		Count_up,
		Channel_A,
		244,
		65535,
		toggle_red
	};

	/* the 32-bit register can hold 16e6 ticks, green LED blinks every second */
	Timer_configuration timer2_config = {
		Timer2, 
		periodic, 
		Count_up,
		No_Channels,
		1,
		16e6,
		toggle_green
	};
	

	Timer_init(&timer0b_config);
	Timer_init(&timer1b_config);
	Timer_init(&timer2_config);

	/* uncomment one timer at a time */
	//Timer_start(Timer0, Channel_B);
	//Timer_start(Timer1, Channel_A);
	Timer_start(Timer2, No_Channels);

	while(1){
		if (Switch_isPressed(SW1)){
			Timer_stop(Timer2, No_Channels);
		}
	}
}

