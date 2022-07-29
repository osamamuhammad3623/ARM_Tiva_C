#include "tm4c123gh6pm_registers.h"
#include "led.h"
#include "sys_tick.h"

void toggle(){
  LED_Toggle(GREEN);
}

int main(){
  LED_Configure(GREEN);

  SysTick_init(0xFFFFF, toggle);
  SysTick_start();
  
  while (1){

  } 
}