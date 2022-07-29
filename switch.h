#ifndef BUILTIN_SWITCH_H_
#define BUILTIN_SWITCH_H_

#include <stdint.h>

typedef enum{
    SW1=4, SW2=0
}Switch_Pin;


/*
 * Description: Configure one of the built-in switches
 *      1.make the pin an input pin
 *      2.no alternate function
 *      3.enable pull-up resistor
 *      3.digital enable
 * */
void Switch_Configure(Switch_Pin sw);


/*
 * Description: Check whether a switch is pressed on not.
 *              return 1 if pressed, 0 otherwise
 * */
uint8_t Switch_isPressed(Switch_Pin sw);

#endif /* BUILTIN_SWITCH_H_ */
