#ifndef BUILTIN_LED_H_
#define BUILTIN_LED_H_

typedef enum {
    RED=1, BLUE=2, GREEN=3
}LED_Color;

class BuiltIn_Led{
    LED_Color color; /* LED color, red is the default */

public:

   /*
    * Description: Configure a specific internal LED
    *      1.make the pin an output pin
    *      2.no alternate function
    *      3.digital enable
    *      4.clear data register
    * */
    BuiltIn_Led(LED_Color c);

    /*
    *Description: enable only a specific LED [other LEDs are disabled]
    * */
    void Enable(void);

    /*
    *Description: toggle the LED
    * */
    void Toggle(void);

    /*
    * Description: disable the LED
    * */
    void Disable(void);

    /*
    * Description: disable all LEDs
    * */
	static void Disable_All(void);
};

#endif /* BUILTIN_LED_H_ */
