#include "tm4c123gh6pm_registers.h"
#include <stdint.h>
#include "basic_gpio.h"
#include "common_macros.h"


void GPIO_writePin(GPIO_Port port, GPIO_Pin pin, uint8_t data){
    switch (port)
    {
    case PORTA:
        if (data){
            SET_BIT(GPIO_PORTA_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTA_DATA_REG, pin);
        }
        break;
    
    case PORTB:
        if (data){
            SET_BIT(GPIO_PORTB_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTB_DATA_REG, pin);
        }
        break;
    
    case PORTC:
        if (data){
            SET_BIT(GPIO_PORTC_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTC_DATA_REG, pin);
        }
        break;

    case PORTD:
        if (data){
            SET_BIT(GPIO_PORTD_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTD_DATA_REG, pin);
        }
        break;
    
    case PORTE:
        if (data){
            SET_BIT(GPIO_PORTE_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTE_DATA_REG, pin);
        }
        break;
    
    case PORTF:
        if (data){
            SET_BIT(GPIO_PORTF_DATA_REG, pin);
        }else{
            CLEAR_BIT(GPIO_PORTF_DATA_REG, pin);
        }
        break;
    
    default:
        break;
    }
}

uint8_t GPIO_ReadPin(GPIO_Port port, GPIO_Pin pin){

    switch (port)
    {
    case PORTA:
        return (GPIO_PORTA_DATA_REG & (1<<pin));
    
    case PORTB:
        return (GPIO_PORTB_DATA_REG & (1<<pin));
    
    case PORTC:
        return (GPIO_PORTC_DATA_REG & (1<<pin));
    
    case PORTD:
        return (GPIO_PORTD_DATA_REG & (1<<pin));
    
    case PORTE:
        return (GPIO_PORTE_DATA_REG & (1<<pin));

    case PORTF:
        return (GPIO_PORTF_DATA_REG & (1<<pin));

    default:
        return -1;
    }
}

void GPIO_init(const GPIO_Configuration * config){
    SET_BIT(SYSCTL_REGCGC2_REG, config->port); /* enable clock for the port */
    if (config->port == PORTA){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTA_DIR_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTA_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTA_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTA_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTA_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTA_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */

            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTA_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTA_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTA_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTA_DEN_REG, config->pin);
        }
    }

    else if (config->port == PORTB){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTB_DIR_REG, config->pin);

        }else{
            CLEAR_BIT(GPIO_PORTB_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTB_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTB_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTB_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTB_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */
            
            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTB_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTB_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTB_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTB_DEN_REG, config->pin);
        }
    }

    else if (config->port == PORTC){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTC_DIR_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTC_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTC_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTC_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTC_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTC_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */
            
            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTC_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTC_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTC_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTC_DEN_REG, config->pin);
        }
    }

    else if (config->port == PORTD){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTD_DIR_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTD_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTD_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTD_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTD_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTD_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */
            
            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTD_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTD_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTD_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTD_DEN_REG, config->pin);
        }
    }

    else if (config->port == PORTE){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTE_DIR_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTE_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTE_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTE_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTE_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTE_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */
            
            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTE_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTE_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTE_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTE_DEN_REG, config->pin);
        }
    }

    else if (config->port == PORTF){
        /* Configurate direction */
        if (config->dir == Output_Pin){
            SET_BIT(GPIO_PORTF_DIR_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTF_DIR_REG, config->pin);
        }

        /* Configurate function type */
        if (config->type == GPIO){
            CLEAR_BIT(GPIO_PORTF_AFSEL_REG, config->pin);
        }else {
            SET_BIT(GPIO_PORTF_AFSEL_REG, config->pin);
        }

        /* Configurate internal resistor */
        if (config->internalR != Disable_internal_resistor){

            GPIO_PORTF_LOCK_REG = 0x4C4F434B; /* unlock commit reg. */
            SET_BIT(GPIO_PORTF_CR_REG,config->pin) ; /* enable commit reg. to control PUR/PDR reg. */
            
            if (config->internalR == Pull_up_resistor){ 
                SET_BIT(GPIO_PORTF_PUR_REG, config->pin); /* enable PUR for the pin */
            }else{
                SET_BIT(GPIO_PORTF_PDR_REG, config->pin); /* enable PDR for the pin */
            }
        }

        /* Configurate Digital IO */
        if (config->isDigital == Digital_Pin){
            SET_BIT(GPIO_PORTF_DEN_REG, config->pin);
        }else{
            CLEAR_BIT(GPIO_PORTF_DEN_REG, config->pin);
        }
    }

    /* Configure data */
    if (config->dir == Output_Pin){
        GPIO_writePin(config->port, config->pin, config->data);
    }

}

void GPIO_setPinDirection(GPIO_Port port, GPIO_Pin pin, GPIO_Direction dir){
	switch(port){
		case PORTA:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTA_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTA_DIR_REG,pin);
			}
			break;
			
		case PORTB:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTB_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTB_DIR_REG,pin);
			}
			break;
			
		case PORTC:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTC_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTC_DIR_REG,pin);
			}
			break;
			
		case PORTD:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTD_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTD_DIR_REG,pin);
			}
			break;
			
		case PORTE:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTE_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTE_DIR_REG,pin);
			}
			break;
			
		case PORTF:
			if(dir == Output_Pin)
			{
				SET_BIT(GPIO_PORTF_DIR_REG,pin);
			}
			else{
				CLEAR_BIT(GPIO_PORTF_DIR_REG,pin);
			}
			break;
	}
}
