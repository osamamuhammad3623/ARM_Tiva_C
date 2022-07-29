#include "tm4c123gh6pm_registers.h"
#include "led.h"
#include <stdint.h>

void wait_sec(){
  for (int32_t i=0; i< 1e6; i++ );
}

int main(){
  LED_Configure(GREEN);
  LED_Configure(RED);
  LED_Configure(BLUE);

  while (1){
    LED_Disable();
    LED_Enable(GREEN);
    wait_sec();

    LED_Disable();
    LED_Enable(RED);
    wait_sec();

    LED_Disable();
    LED_Enable(BLUE);
    wait_sec();
  } 
}