#include "unity.h"
#include "ledDriver.h"
#include <stdint.h>

void setUp(){

}

void tearDown(){
	driverAddress = 0;
}

// Test 1
void testLedDriverCreateDebeIniciarConLedsApagados(){
	driverAddress = 0xFFFF;
	ledDriver_create();
	TEST_ASSERT_EQUAL_UINT16 (0, driverAddress);
}

// Test 2
void testLedDriverLedOnEnciendeCadaLed(){

	ledDriver_create();
	ledDriver_led_on(0);
	TEST_ASSERT_EQUAL_UINT16 (0x0001, driverAddress);
	ledDriver_led_on(1);
        TEST_ASSERT_EQUAL_UINT16 (0x0003, driverAddress);
	ledDriver_led_on(2);
        TEST_ASSERT_EQUAL_UINT16 (0x0007, driverAddress);
	ledDriver_led_on(3);
        TEST_ASSERT_EQUAL_UINT16 (0x000F, driverAddress);
	ledDriver_led_on(4);
        TEST_ASSERT_EQUAL_UINT16 (0x001F, driverAddress);
	ledDriver_led_on(5);
        TEST_ASSERT_EQUAL_UINT16 (0x003F, driverAddress);
	ledDriver_led_on(6);
        TEST_ASSERT_EQUAL_UINT16 (0x007F, driverAddress);
	ledDriver_led_on(7);
        TEST_ASSERT_EQUAL_UINT16 (0x00FF, driverAddress);
	ledDriver_led_on(8);
        TEST_ASSERT_EQUAL_UINT16 (0x01FF, driverAddress);
	ledDriver_led_on(9);
        TEST_ASSERT_EQUAL_UINT16 (0x03FF, driverAddress);
	ledDriver_led_on(10);
        TEST_ASSERT_EQUAL_UINT16 (0x07FF, driverAddress);
	ledDriver_led_on(11);
        TEST_ASSERT_EQUAL_UINT16 (0x0FFF, driverAddress);
	ledDriver_led_on(12);
        TEST_ASSERT_EQUAL_UINT16 (0x1FFF, driverAddress);
	ledDriver_led_on(13);
        TEST_ASSERT_EQUAL_UINT16 (0x3FFF, driverAddress);
	ledDriver_led_on(14);
        TEST_ASSERT_EQUAL_UINT16 (0x7FFF, driverAddress);
	ledDriver_led_on(15);
        TEST_ASSERT_EQUAL_UINT16 (0xFFFF, driverAddress);
}

// Test 3
void testLedDriverLedOffApagaCadaLed(){

	driverAddress=0xFFFF;
        ledDriver_led_off(0);
        TEST_ASSERT_EQUAL_UINT16 (0xFFFE, driverAddress);
	ledDriver_led_off(1);
	TEST_ASSERT_EQUAL_UINT16 (0xFFFC, driverAddress);
        ledDriver_led_off(2);
        TEST_ASSERT_EQUAL_UINT16 (0xFFF8, driverAddress);
	ledDriver_led_off(3);
        TEST_ASSERT_EQUAL_UINT16 (0xFFF0, driverAddress);
	ledDriver_led_off(4);
        TEST_ASSERT_EQUAL_UINT16 (0xFFE0, driverAddress);
	ledDriver_led_off(5);
        TEST_ASSERT_EQUAL_UINT16 (0xFFC0, driverAddress);
	ledDriver_led_off(6);
        TEST_ASSERT_EQUAL_UINT16 (0xFF80, driverAddress);
	ledDriver_led_off(7);
        TEST_ASSERT_EQUAL_UINT16 (0xFF00, driverAddress);
	ledDriver_led_off(8);
        TEST_ASSERT_EQUAL_UINT16 (0xFE00, driverAddress);
	ledDriver_led_off(9);
        TEST_ASSERT_EQUAL_UINT16 (0xFC00, driverAddress);
	ledDriver_led_off(10);
        TEST_ASSERT_EQUAL_UINT16 (0xF800, driverAddress);
	ledDriver_led_off(11);
        TEST_ASSERT_EQUAL_UINT16 (0xF000, driverAddress);
	ledDriver_led_off(12);
        TEST_ASSERT_EQUAL_UINT16 (0xE000, driverAddress);
	ledDriver_led_off(13);
        TEST_ASSERT_EQUAL_UINT16 (0xC000, driverAddress);
	ledDriver_led_off(14);
        TEST_ASSERT_EQUAL_UINT16 (0x8000, driverAddress);
	ledDriver_led_off(15);
        TEST_ASSERT_EQUAL_UINT16 (0x0000, driverAddress);

}

// Test 4
void testLedDriverMultipleLedSetEnciendeYApagaVariosLedALaVez(){

	ledDriver_create(); // al inicializar driverAddress = 0x0000
	ledDriver_multiple_led_set((uint16_t)0xFF00);

	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(0));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(1));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(2));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(3));
        TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(4));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(5));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(6));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(7));
        TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(8));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(9));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(10));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(11));
        TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(12));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(13));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(14));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(15));

	ledDriver_multiple_led_set(0x0F00);
        TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(12));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(13));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(14));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(15));
}

// Test 5
void testLedDriverDebePoderApagarTodosLosLed(){
	uint16_t i;
	ledDriver_create(); // al inicializar driverAddress = 0x000
	ledDriver_multiple_led_set(0xFFFF);

	for(i=0;i<16;i++){
		ledDriver_led_off(i);
	}
        TEST_ASSERT_EQUAL_UINT16 (0, driverAddress);
}

// Test 6
void testLedDriverDebePoderEncenderTodosLosLed(){
	uint16_t i;
	ledDriver_create(); // al inicializar driverAddress = 0x000

	for(i=0;i<16;i++){
		ledDriver_led_on(i);
	}
        TEST_ASSERT_EQUAL_UINT16 (0xFFFF, driverAddress);
}

// Test 7
void testLedDriverGetStateDevuelveEstadoDeCadaLedIndividual(){
	
	ledDriver_create(); // al inicializar driverAddress = 0x000
	ledDriver_led_on(4);
	ledDriver_led_on(7);
	ledDriver_led_on(14);
	ledDriver_led_on(15);
        TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(0));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(1));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(2));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(3));
        TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(4));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(5));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(6));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(7));
        TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(8));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(9));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(10));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(11));
        TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(12));
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(13));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(14));
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(15));
}

// Test 8
void testLedDriverValoresLimite(){
	ledDriver_create(); // al inicializar driverAddress = 0x000

	ledDriver_led_on(0);
	TEST_ASSERT_EQUAL_UINT16 (0x0001, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(0));	
	ledDriver_led_off(0);
	TEST_ASSERT_EQUAL_UINT16 (0x0000, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(0));

	ledDriver_led_on(0);
	TEST_ASSERT_EQUAL_UINT16 (0x0001, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (1, ledDriver_get_state(0));	
	ledDriver_led_off(0);
	TEST_ASSERT_EQUAL_UINT16 (0x0000, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (0, ledDriver_get_state(0));

}

// Test 9
void testLedDriverValoresFueraLimite(){

	ledDriver_create(); // Al inicializar driverAddress = 0x000

	// No deberia tener efecto encender/apagar/pedir/estado leds por encima del indice 15
	ledDriver_led_on(15);
	ledDriver_led_on(20);
	TEST_ASSERT_EQUAL_UINT16 (0x0000, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (0xFF, ledDriver_get_state(15));	
	TEST_ASSERT_EQUAL_UINT8 (0xFF, ledDriver_get_state(20));	

	ledDriver_multiple_led_set((uint8_t)0xFF);
	ledDriver_led_off(15);
	ledDriver_led_off(20);
	TEST_ASSERT_EQUAL_UINT16 (0xFFFF, driverAddress);
	TEST_ASSERT_EQUAL_UINT8 (0xFF, ledDriver_get_state(15));	
	TEST_ASSERT_EQUAL_UINT8 (0xFF, ledDriver_get_state(20));

}

