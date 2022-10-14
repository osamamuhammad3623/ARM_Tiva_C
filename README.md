# TM4C123 Drivers [ARM Architecture]

## Implemented C Drivers:
1. SysTick timer
2. Basic GPIO
3. GPTM (supporting 3 16/32-bit timers in port B)

- GPTM driver: Timer0 & Timer1 are configured to work in 16-bit mode (individual mode) where each timer has 2 channels A & B.
               Timer2 is configured to work in 32-bit mode (concatenated channels).

## C++ Drivers:
1. 'BuiltIn Led' class, as a driver for the Tiva C leds [built-in]
2. 'BuiltIn Switch' class, as a driver for the Tiva C switches [built-in]
