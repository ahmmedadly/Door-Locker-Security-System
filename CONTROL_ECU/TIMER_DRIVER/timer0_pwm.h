 /******************************************************************************
 *
 * File Name: timer0_pwm.h
 *
 * Description: timer0_pwm driver header file
 *
 * Author: AHMED ADLY
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "../std_types.h"


/*
 *
 * Description:
 * -The function responsible for trigger the Timer0 with the PWM Mode.
 * -Setup the PWM mode with Non-Inverting.
 * -Setup the prescaler with F_CPU/8.
 * -Setup the compare value based on the required input duty cycle
 * -Setup the direction for OC0 as output pin through the GPIO driver.
 * -The generated PWM signal frequency will be 500Hz to control the DC
 *		Motor speed.
*/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
