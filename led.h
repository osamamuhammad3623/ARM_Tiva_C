#ifndef BUILTIN_LED_H_
#define BUILTIN_LED_H_


typedef enum {
    RED=1, BLUE=2, GREEN=3
}LED_Color;

/*
 * Description: Configure a specific internal LED
 *      1.make the pin an output pin
 *      2.no alternate function
 *      3.digital enable
 *      4.clear data register
 * */
void LED_Configure(LED_Color color);

/*
 *Description: enable only a specific LED [other LEDs are disabled]
 * */
void LED_Enable(LED_Color color);

/*
 *Description: toggle the LED
 * */
void LED_Toggle(LED_Color color);

/*
 * Description: disable all LEDs
 * */
void LED_Disable(void);

#endif /* BUILTIN_LED_H_ */
