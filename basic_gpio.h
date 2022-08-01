#ifndef BASIC_GPIO_H_
#define BASIC_GPIO_H_

#include <stdint.h>

/********************************************************/
/* Type definitions */
/********************************************************/

#define LOGIC_HIGH	(1)
#define LOGIC_LOW	(0)

typedef enum{
	PORTA=0, PORTB, PORTC, PORTD, PORTE, PORTF
}GPIO_Port;

typedef enum{
	Pin_0 = 0, Pin_1, Pin_2, Pin_3, Pin_4, Pin_5, Pin_6, Pin_7
}GPIO_Pin;

typedef enum{
	Input_Pin=0, Output_Pin=1
}GPIO_Direction;

typedef enum{
	GPIO, AFSEL
}GPIO_FunctionType;

typedef enum{
	Digital_Pin, Analog_Pin
}GPIO_DigitalType;

typedef enum{
	Pull_up_resistor, Pull_down_resistor, Disable_internal_resistor
}GPIO_InternalResistor;

typedef struct
{
	GPIO_Port port;
	GPIO_Pin pin;
	uint8_t data; /* boolean value */
	GPIO_DigitalType isDigital;
	GPIO_FunctionType type;
	GPIO_Direction dir;
	GPIO_InternalResistor internalR;
} GPIO_Configuration;


/********************************************************/
/* Function Prototypes */
/********************************************************/

/*
Description: Configure & initialize a GPIO pin.
						- specify its Port and pin number.
						- Enable port clock
						- Configure the pin as Input on Output
						- Configure the pin as GPIO pin or has an Alternate function
						- Set if it's a Digital IO or not
						- Enable/Disable internal pull-up/down resistor.
*/
void GPIO_init(const GPIO_Configuration * config);

void GPIO_writePin(GPIO_Port port, GPIO_Pin pin, uint8_t data);

uint8_t GPIO_readPin(GPIO_Port port, GPIO_Pin pin);

void GPIO_setPinDirection(GPIO_Port port, GPIO_Pin pin, GPIO_Direction dir);

#endif /* BASIC_GPIO_H_ */
