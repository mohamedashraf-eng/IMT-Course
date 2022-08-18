# IMT-Course

## Assignments
___
### Assignment 1

Traffic Light Simulator

Mechanism:
* Turn on green led for 10 seconds.
* Turn on yellow led for 3 seconds.
* Turn on red led for 10 seconds.
* The seconds counter is represented by the two seven segement.

Table of contents:
|Component|Quantity|Usage|
|----------|--------|------|
|Red Led|1|To repersent the Stop|
|Yellow Led|1|To repersent the Steady|
|Green Led|1|To repersent the Go|
|Seven Segement|2|To repersent the count down digits|

### Assignment 2
Light Animation System
Using only 3 DIP switch (that represents 8 different modes).

Modes:
1. Flashing every 500 ms
2. Shifting Left every 250 ms
3. Shifting Right every 250 ms
4. 2-LEDs Converging every 300 ms
5. 2-LEDs Diverging every 300 ms
6. Ping Pong effect every 250 ms
7. Incrementing (Snake effect) every 300 ms
8. 2-LEDs Converging/Diverging every 300 ms

Table of contents:
|Component|Quantity|Usage|
|----------|--------|------|
|Leds|8|To represent the modes animation|
|3-DIP switch|1|To switch between modes|

___
## Drivers
Set of microcontroller drivers internally / externally for easy to use for normal user.

Architecture: Static - Basic

Folder structure:

ATmega32_Drivers: 1.APP: 1. main.c
                  2.HAL: 1.LED 2.BUTTON 3.SSD
                  3.MCAL: 1.DIO
                  4.LIB: 1. std_types.h 2.bit_math.h 3.std_libs.h
```
project
│   README.md  
│
└───Assignments
│   │   file011.txt
│   │   file012.txt
│   │
│   └───01-assignment
│       │   main.c
│       │   assignment1.h
│       │   assignment1.c
│       │   LIB
│   └───02-assignment
│       │   main.c
│       │   assignment2.h
│       │   assignment2.c
│       │   LIB
└───ATmega32_Drivers
│   └───APP
│       │   main.c
│   └───HAL
│       └───LED
|           | LED_Private.h
|           | LED_Config.h
|           | LED_Interface.h
|           | LED_Program.c
|       └───BUTTON
|           | BUTTON_Private.h
|           | BUTTON_Config.h
|           | BUTTON_Interface.h
|           | BUTTON_Program.c
|       └───SSD
|           | SSD_Private.h
|           | SSD_Config.h
|           | SSD_Interface.h
|           | SSD_Program.c
|   └───MCAL
|       └───DIO
|           | DIO_Registers.h
|           | DIO_Private.h
|           | DIO_Config.h
|           | DIO_Interface.h
|           | DIO_Program.c
|   └───LIB
|       | bit_math.h
|       | std_types.h
|       | std_libs.h
```
___               
|Driver|Type|State|
|----------|--------|------|
|Digital Input Output Driver|Internal|Done|
|Led|External|Done|
|Button|External|Done|
|Seven Segement Digit|External|Done|
