
#ifndef _LEDDRIVER_H_
#define _LEDDRIVER_H_

#include <stdint.h>

void ledDriver_create(uint16_t *address);

void ledDriver_led_on(uint16_t *address,uint8_t led);

void ledDriver_led_off(uint16_t *address,uint8_t led);

#endif 
