#include "led.h"
#include "common_macros.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

BuiltIn_Led::BuiltIn_Led(LED_Color c) : color{c}{
  this->Configure();
}

void BuiltIn_Led::Configure(void)
{
  SYSCTL_RCGC2_R |= (1 << 5); /* enable clock for port F */
  SET_BIT(GPIO_PORTF_DIR_R , color);
  CLEAR_BIT(GPIO_PORTF_AFSEL_R, color);
  SET_BIT(GPIO_PORTF_DEN_R , color);
  CLEAR_BIT(GPIO_PORTF_DATA_R , color);
}

void BuiltIn_Led::Enable(void)
{
  GPIO_PORTF_DATA_R |= (1<<color);
}

void BuiltIn_Led::Toggle(void){
  GPIO_PORTF_DATA_R ^= (1<<color);
}

void BuiltIn_Led::Disable(void)
{
  GPIO_PORTF_DATA_R &= (~(1<<color));
}

void BuiltIn_Led::Disable_All(void){
	GPIO_PORTF_DATA_R &= (~(0xE));  // clear bits 1,2 and 3 -> 0b1110
}