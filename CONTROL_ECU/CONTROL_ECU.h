/*
 * CONTROL_ECU.h
 *
 *  Created on: Mar 28, 2024
 *      Author: AHMED ADLY
 */
#ifndef CONTROL_ECU_H_
#define CONTROL_ECU_H_

#include "UART_DRIVER/uart.h"
#include "std_types.h"
#include "EXTERNAL_EEPROM/external_eeprom.h"
#include "BUZZER_DRIVER/buzzer.h"
#include "DCMOTOR_DRIVER/dc_motor.h"
#include "TIMER_DRIVER/timer_1.h"
#include "TWI_DRIVER/twi.h"
#include <avr/common.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void secondsCounter(void);
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SUCCESS 1
#define FAILURE 0

#define UART_SEND_PASS_FLAG 0x04
#define UART_CONFIRM_PASS_FLAG 0x05
#define UART_OPEN_DOOR_FLAG 0x06
#define UART_PASS_UNMATCH 0x07
#define UART_READY 0x08



uint16 seconds;

#endif /* CONTROL_ECU_H_ */
