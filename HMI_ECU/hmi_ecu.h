/*
 *  HMI_ECU.h
 *  Created on: Mar 28, 2024
 *  Author: AHMED ADLY
 */
#ifndef HMI_ECU_H_
#define HMI_ECU_H_

#include "LCD_Driver/lcd.h"
#include "KEYPAD_DRIVER/keypad.h"
#include "UART_DRIVER/uart.h"
#include "std_types.h"
#include "TIMER_DRIVER/timer_1.h"
#include <avr/common.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ENTER_BUTTON '='
#define SUCCESS 1
#define FAILURE 0

#define UART_SEND_PASS_FLAG 0x04
#define UART_CONFIRM_PASS_FLAG 0x05
#define UART_OPEN_DOOR_FLAG 0x06
#define UART_PASS_UNMATCH 0x07
#define UART_READY 0x08

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void secondsCounter(void);
void takePassword(uint8 *str);
uint8 createPassword(void);
uint8 checkPassword(void);
void error(void);


#endif /* HMI_ECU_H_ */
