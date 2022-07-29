#include "tm4c123gh6pm_registers.h"
#include "led.h"
#include "switch.h"
#include <stdint.h>

void wait_sec(){
  for (int32_t i=0; i< 1e6; i++ );
}

int main(){
  LED_Configure(GREEN);
  LED_Configure(BLUE);

  Switch_Configure(SW1);
  Switch_Configure(SW2);

  while (1){

    if (Switch_isPressed(SW1)){
      LED_Enable(GREEN);
    }else if (Switch_isPressed(SW2)){
      LED_Enable(BLUE);
    }else{
      LED_Disable();
    }
    
  } 
}