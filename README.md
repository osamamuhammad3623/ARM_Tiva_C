# TM4C123 Drivers [ARM Architecture]

## Implemented Drivers:
1. LEDs [built-in]
2. Switches [built-in]
3. SysTick timer
4. Basic GPIO
5. GPTM (supporting 3 16/32-bit timers in port B)

- GPTM driver: Timer0 & Timer1 are configured to work in 16-bit mode (individual mode) where each timer has 2 channels A & B.
               Timer2 is configured to work in 32-bit mode (concatenated channels).

## C++ Drivers:
- 'BuiltIn Led' class, as a driver for the Tiva C leds.
