#include "led.h"
#include <stdint.h>
#include "common_macros.h"
#include "tm4c123gh6pm_registers.h"

void LED_Configure(LED_Color color)
{
    SYSCTL_REGCGC2_REG |= (1 << 5); /* enable clock for port F */
    SET_BIT(GPIO_PORTF_DIR_REG , color);
    CLEAR_BIT(GPIO_PORTF_AFSEL_REG, color);
    SET_BIT(GPIO_PORTF_DEN_REG , color);
    CLEAR_BIT(GPIO_PORTF_DATA_REG , color);
}

void LED_Enable(LED_Color color)
{
  GPIO_PORTF_DATA_REG |= (1<<color);
}

void LED_Toggle(LED_Color color){
  GPIO_PORTF_DATA_REG ^= (1<<color);
}

void LED_Disable(void)
{
  GPIO_PORTF_DATA_REG &= (~(0xE));  // clear bits 1,2 and 3 -> 0b1110
}
