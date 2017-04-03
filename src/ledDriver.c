#include "ledDriver.h"
  
/**
 * Crea el driver, seteando los led apagados por inicializacion 
 *
 * @param uint16_t* address Map del driver en memoria
 */
void ledDriver_create(uint16_t* address){
	driverAddress = address;
	*driverAddress = 0;
}

/**
 * Enciende el led indicado por el parametro led. Si el parametro esta fuera del rango 0-15 no hace nada 
 *
 * @param uint8_t led Indica el led a apagar, de 0 a 15.
 * @return void
 */
void ledDriver_led_on(uint8_t led){
	if(led<16){
        	*driverAddress |= (1<<led);
	}
}

/**
 * Apaga el led indicado por el parametro led. Si el parametro esta fuera del rango 0-15 no hace nada 
 *
 * @param uint8_t led Indica el led a apagar, de 0 a 15.
 * @return void
 */
void ledDriver_led_off(uint8_t led){
	if(led<16){
		*driverAddress ^= (1<<led);
	}
}


/**
 * Enciende/Apaga varios leds segun la mascara recibida como parametro  
 *
 * @param uint16_t ledMask Indica los leds encendidos (1) y apagados (0) en codificacion binaria, 
 * 			   uno por bit empezando por el led 0 en el LSB.
 * @return void 
 */
void ledDriver_multiple_led_set(uint16_t ledMask){
	*driverAddress = (uint16_t)ledMask;
}


/**
 * Devuelve el estado del led indicado por parametro. Si el parametro esta fuera del rango 0-15 devuelve el valor de error 0xFF 
 *
 * @param uint8_t led Indica el led a consultar.
 * @return uint8_t Indica el valor del led: encendido (1), apagado (0) o led inexistente (0xFF)
 */
uint8_t ledDriver_get_state(uint8_t led){
	uint8_t state=0xFF;
	if(led<16){
		if((*driverAddress & (1<<led))>0){
			state=1;
		}else{
			state=0;		
		}
	}
	return state;
}


/**
 * Enciende o apaga todos los led en funcion del parametro power 
 *
 * @param uint8_t power Indica la accion a realizar:power>0 Leds encendidos, power=0 Leds apagados
 * @return void
 */
void ledDriver_all_led(uint8_t power){
	if(power>0){
		*driverAddress = 0xFFFF;
	}else
		*driverAddress = 0;
}

