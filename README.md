# BMP180_for_STM32_HAL
An STM32 HAL library written for the BMP180 temperature/pressure sensor. 

## To test
* Minimal setup:
```
                                             _________
                                    VDD 1 --|      O  |
                                    GND 2 --|      _  |
                                   SCL1 3 --|     |_| |
                                   SDA1 4 --|_________|
                                   
 ```
* In STM32CubeIDE, include [`bmp180_for_stm32_hal.h`](./bmp180_for_stm32_hal.h) and [`bmp180_for_stm32_hal.c`](./bmp180_for_stm32_hal.c).
* Complie and flash [`main.c`](./examples/main.c) in [`./examples`](./examples) to microcontroller.
* Read the results from a UART monitor.
* Refer to [datasheets](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwi23vToqPLpAhUDZt4KHTPUA-sQFjAAegQIBBAB&url=https%3A%2F%2Fcdn-shop.adafruit.com%2Fdatasheets%2FBST-BMP180-DS000-09.pdf&usg=AOvVaw2GVPbzAj6_NxVb-N7lcGQe) for further information.
