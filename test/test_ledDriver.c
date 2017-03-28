#include "unity.h"
#include "ledDriver.h"
#include <stdint.h>

uint16_t driverAddress;

void setUp(){

}

void tearDown(){
	driverAddress = 0;
}

void testLedDriverCreateDebeIniciarConLedsApagados(){
	driverAddress = 0xffff;
	ledDriver_create(&driverAddress);
	TEST_ASSERT_EQUAL_UINT16 (0, driverAddress);
}


void testLedDriverEnciendeYApagaCadaLed(){
	driverAddress=0;

	ledDriver_led_on(&driverAddress,0);
	TEST_ASSERT_EQUAL_UINT16 (0x01, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,1);
        TEST_ASSERT_EQUAL_UINT16 (2, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,2);
        TEST_ASSERT_EQUAL_UINT16 (4, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,3);
        TEST_ASSERT_EQUAL_UINT16 (8, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,4);
        TEST_ASSERT_EQUAL_UINT16 (16, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,5);
        TEST_ASSERT_EQUAL_UINT16 (32, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,6);
        TEST_ASSERT_EQUAL_UINT16 (64, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,7);
        TEST_ASSERT_EQUAL_UINT16 (128, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,8);
        TEST_ASSERT_EQUAL_UINT16 (0x0100, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,9);
        TEST_ASSERT_EQUAL_UINT16 (0x0200, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,10);
        TEST_ASSERT_EQUAL_UINT16 (0x0400, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,11);
        TEST_ASSERT_EQUAL_UINT16 (0x0800, driverAddress);
        driverAddress=0;
	ledDriver_led_on(&driverAddress,12);
        TEST_ASSERT_EQUAL_UINT16 (0x1000, driverAddress);
	driverAddress=0;        
	ledDriver_led_on(&driverAddress,13);
        TEST_ASSERT_EQUAL_UINT16 (0x2000, driverAddress);
	driverAddress=0;        
	ledDriver_led_on(&driverAddress,14);
        TEST_ASSERT_EQUAL_UINT16 (0x4000, driverAddress);
	driverAddress=0;
        ledDriver_led_on(&driverAddress,15);
        TEST_ASSERT_EQUAL_UINT16 (0x8000, driverAddress);

	driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,0);
        TEST_ASSERT_EQUAL_UINT16 (0xFFFE, driverAddress);
	driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,1);
        TEST_ASSERT_EQUAL_UINT16 (0xFFFD, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,2);
        TEST_ASSERT_EQUAL_UINT16 (0xFFFB, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,3);
        TEST_ASSERT_EQUAL_UINT16 (0xFFF7, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,4);
        TEST_ASSERT_EQUAL_UINT16 (0xFFEF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,5);
        TEST_ASSERT_EQUAL_UINT16 (0xFFDF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,6);
        TEST_ASSERT_EQUAL_UINT16 (0xFFBF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,7);
        TEST_ASSERT_EQUAL_UINT16 (0xFF7F, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,8);
        TEST_ASSERT_EQUAL_UINT16 (0xFEFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,9);
        TEST_ASSERT_EQUAL_UINT16 (0xFDFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,10);
        TEST_ASSERT_EQUAL_UINT16 (0xFBFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,11);
        TEST_ASSERT_EQUAL_UINT16 (0xF7FF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,12);
        TEST_ASSERT_EQUAL_UINT16 (0xEFFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,13);
        TEST_ASSERT_EQUAL_UINT16 (0xDFFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,14);
        TEST_ASSERT_EQUAL_UINT16 (0xBFFF, driverAddress);
        driverAddress=0xFFFF;
        ledDriver_led_off(&driverAddress,15);
        TEST_ASSERT_EQUAL_UINT16 (0x7FFF, driverAddress);

}
