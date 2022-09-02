#ifndef BASIC_TIMER_H_
#define BASIC_TIMER_H_
#include <stdint.h>

/********************************************************/
/* Type definitions */
/********************************************************/

typedef enum {
    one_shot = 0x1, periodic = 0x2
} Timer_mode;

typedef enum{
    Timer0 = 0,
    Timer1 = 1,
    Timer2 = 2
} Timer_ID;

typedef enum{
    Count_down=0, Count_up=1
}Count_Type;

typedef enum{
    Channel_A, Channel_B, No_Channels
}Timer_Channel;

typedef struct{
	Timer_ID timer_ID;
	Timer_mode mode;
    Count_Type dir;
    Timer_Channel channel;

    /* # of clocks per timer tick */
    /* if it's = 1; then 1 clockcycle = 1 tick (timer will increment/decrement by 1 every clockcycle)
       if it's = 256; then the timer will increment/decrement once every 256 clockcycles */
    /* range is [1,256] */
    uint16_t clocks_per_tick;
	uint32_t compareValue;
	void volatile (* callBack) (void); /* pointer to call-back function */
}Timer_configuration;


/********************************************************/
/* Function Prototypes */
/********************************************************/

/*
Description: A function to intialize the timer, supports One-shot and Periodic modes
                - Enable timer clock and its port clock
                - set alternate function
                - configure counting up or counting down
                - set compare value 
                - set the call-back function
                - Enable timer interrupt

Note: Timer0 & Timer1 are configured as 16-bit timers, thus you have to specify the channel,
        but Timer2 is configured as a 32-bit timer, so there are no channels */
void Timer_init(const Timer_configuration* timer_config);

/* A function to enable the timer to count */
void Timer_start(Timer_ID timer_id, Timer_Channel channel);

/* A function to stop the timer counting */
void Timer_stop(Timer_ID timer_id, Timer_Channel channel);

#endif /* BASIC_TIMER_H_ */
