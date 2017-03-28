#include "ledDriver.h"

void ledDriver_create(uint16_t *address){
	*address = 0;
}

void ledDriver_led_on(uint16_t *address,uint8_t led){
        *address |= 1<<led;
}

void ledDriver_led_off(uint16_t *address,uint8_t led){
        *address ^= 1<<led;
}

