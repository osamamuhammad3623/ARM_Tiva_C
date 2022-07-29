#include <stdint.h>
#include "switch.h"
#include "common_macros.h"
#include "tm4c123gh6pm_registers.h"

void Switch_Configure(Switch_Pin sw){
	SYSCTL_REGCGC2_REG |= (1 << 5); /* enable clock for port F */
	CLEAR_BIT(GPIO_PORTF_DIR_REG, sw);
	CLEAR_BIT(GPIO_PORTF_AFSEL_REG, sw);
	GPIO_PORTF_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
	SET_BIT(GPIO_PORTF_CR_REG, sw); /* enable commit reg. to control PUR reg. */
	SET_BIT(GPIO_PORTF_PUR_REG, sw);
	SET_BIT(GPIO_PORTF_DEN_REG, sw);
}

uint8_t Switch_isPressed(Switch_Pin sw){
    if (BIT_IS_CLEAR(GPIO_PORTF_DATA_REG,sw))
        return 1;

    return 0;
}
