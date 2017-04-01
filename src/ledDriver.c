#include "ledDriver.h"


/*
 * Crea el driver, seteando los led apagados por inicializacion 
 *
 */
void ledDriver_create(){
	driverAddress = 0;
}

/*
 * Enciende el led indicado por el parametro led 
 *
 */
void ledDriver_led_on(uint8_t led){
	if(led<16)
        	driverAddress |= (1<<led);
}

/*
 * Apaga el led indicado por el parametro led 
 *
 */
void ledDriver_led_off(uint8_t led){
	if(led<16)
		driverAddress ^= (1<<led);
}

/*
 * Enciende/Apaga varios leds segun la mascara recibida como parametro 
 *
 */
void ledDriver_multiple_led_set(uint16_t ledMask){
	driverAddress = (uint16_t)ledMask;
}

/*
 * Devuelve el estado del led indicado por parametro 
 *
 */
uint8_t ledDriver_get_state(uint8_t led){
	uint8_t state=0xFF;
	if(led<16){
		if((driverAddress &= (1<<led))>0){
			state=1;
		}else{
			state=0;		
		}
	}
	return state;
}

/*
 * Enciende o apaga todos los led en funcion del parametro power
 *
 * power>0 Leds encendidos, power=0 Leds apagados
 */
void ledDriver_all_led(uint8_t power){
	if(power>0){
		driverAddress = 0xFFFF;
	}else
		driverAddress = 0;
}

