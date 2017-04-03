
#ifndef _LEDDRIVER_H_
#define _LEDDRIVER_H_

#include <stdint.h>

/**
* Mapping de estado de 16 leds. Desde el led 0 en LSB a el 15 en MSB 
*/
uint16_t driverAddress; 

void ledDriver_create(void);

void ledDriver_led_on(uint8_t led);

void ledDriver_led_off(uint8_t led);

void ledDriver_multiple_led_set(uint16_t led_mask);

void ledDriver_all_led(uint8_t power);

uint8_t ledDriver_get_state(uint8_t led);

#endif 
