/***********************************************************************************************************
 ===========================================================================================================
 Name        :  Final Project
 Author      :  AHMED ADLY
 date        :  13/3/2024
 Description:   CONTROL_ECU in Door Locker Security System using ATmega32 microcontroller ,responsible for
 all the processing and decisions in the system like password checking, open the door and activate the system
 alarm
 ===========================================================================================================
 ***********************************************************************************************************/

#include "control_ecu.h"
/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/
int main() {

	uint8 current_operation, idx, byte, error_flag = 0, password[5],
			password_confirmation[5];
	TWI_ConfigType twi = { 400000, 1 };
	Timer1_ConfigType timer1 = { 0, 31250, TIMER1_FRQ256, TIMER1_CTC };
	UART_ConfigType uart = { INTERRUPT_DISABLE, EVEN_PARITY, ONE_BIT, EIGHT_BIT,
			BAUD_RATE_9600 };

	sei();

	Timer1_init(&timer1);
	Timer1_setCallBack(secondsCounter);
	UART_init(&uart);
	TWI_init(&twi);
	DcMotor_Init();
	Buzzer_init();

	while (1) {
		current_operation = UART_recieveByte();

		if (current_operation == UART_SEND_PASS_FLAG || current_operation == UART_CONFIRM_PASS_FLAG) {
			for (idx = 0; idx < 5; idx++) {
				password[idx] = UART_recieveByte();
			}

		}

		if (current_operation == UART_SEND_PASS_FLAG) {
			for (idx = 0; idx < 5; idx++) {
				password_confirmation[idx] = UART_recieveByte();
			}

			error_flag = 0;
			for (idx = 0; idx < 5; idx++) {
				if (password_confirmation[idx] != password[idx])
					error_flag = 1;
			}

			UART_sendByte(UART_READY);
			if (error_flag) {
				UART_sendByte(FAILURE);
			} else {
				UART_sendByte(SUCCESS);
				EEPROM_writeByte(0, password);
			}

		} else if (current_operation == UART_CONFIRM_PASS_FLAG) {

			error_flag = 0;
			for (idx = 0; idx < 5; idx++) {
				EEPROM_readByte(idx, &byte);
				if (byte != password[idx]) {
					error_flag = 1;
				}
				_delay_ms(10);
			}

			UART_sendByte(UART_READY);
			if (error_flag) {
				UART_sendByte(FAILURE);
			} else {
				UART_sendByte(SUCCESS);
			}

		} else if (current_operation == UART_OPEN_DOOR_FLAG) {
			seconds = 0;

			DcMotor_Rotate(CW, 100);
			while (seconds < 15);

			DcMotor_Rotate(STOP, 0);
			while (seconds < 18);

			DcMotor_Rotate(ACW, 100);
			while (seconds < 33);

			DcMotor_Rotate(STOP, 0);
		} else if (current_operation == UART_PASS_UNMATCH) {
			seconds = 0;
			Buzzer_on();
			while (seconds < 60);
			Buzzer_off();
		}
	}
}

void secondsCounter(void) {
	seconds++;
}
