#ifndef BUILTIN_SWITCH_H_
#define BUILTIN_SWITCH_H_

#include <stdint.h>

typedef enum{
    SW1=4, SW2=0
}Switch_Pin;

class BuiltIn_Switch{
    Switch_Pin sw;
public:

    /*
    * Description: Configure one of the built-in switches
    *      1.make the pin an input pin
    *      2.no alternate function
    *      3.enable pull-up resistor
    *      3.digital enable
    * */
    BuiltIn_Switch(Switch_Pin user_switch);

    /*
    * Description: Check whether a switch is pressed on not.
    *              return 1 if pressed, 0 otherwise
    * */
    uint8_t isPressed(void);
};

#endif /* BUILTIN_SWITCH_H_ */
