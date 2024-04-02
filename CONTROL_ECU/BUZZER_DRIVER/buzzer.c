 /******************************************************************************
 *
 * File Name: buzzer.c
 *
 * Description: source file for Buzzer Driver
 *
 * Author: AHMED ADLY
 *
 *******************************************************************************/


#include "../BUZZER_DRIVER/buzzer.h"
#include "../GPIO_DRIVER/gpio.h"

/*
 * Description:
 * Setup the direction for the buzzer pin as output pin through the GPIO driver.
 * Turn off the buzzer through the GPIO.
 */
void Buzzer_init(){
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
}

/*
 * Description:
 * Function to enable the Buzzer through the GPIO.
 */
void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID ,LOGIC_HIGH);
}

/*
 * Description:
 * Function to disable the Buzzer through the GPIO
 */
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID ,LOGIC_LOW);
}
