/***********************************************************************************************************
 ===========================================================================================================
 Name        :  Final Project
 Author      :  AHMED ADLY
 date        :  13/3/2024
 Description:   HMI_ECU(Human Machine Interface) in Door Locker Security System using ATmega32 microcontroller
 responsible interaction with the user to take inputs through keypad and display messages on the LCD.
 ===========================================================================================================
 ***********************************************************************************************************/
#include "hmi_ecu.h"

/*******************************************************************************
 *                              Functions Definitions                          *
 *******************************************************************************/

	uint16 seconds;
int main(){
	uint8 unMatchCounter,pressedButton;
	Timer1_ConfigType timer1={0,31250,TIMER1_FRQ256, TIMER1_CTC};
	 UART_ConfigType uart = { INTERRUPT_DISABLE, EVEN_PARITY, ONE_BIT,
				EIGHT_BIT, BAUD_RATE_9600 };

	sei();

	Timer1_init(&timer1);
	Timer1_setCallBack(secondsCounter);
	UART_init(&uart);
	LCD_init();

	/* create new password to the system */
	while(createPassword()==FAILURE);

	while(1){
		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString("+ : Open Door");
		LCD_moveCursor(1,0);
		LCD_displayString("- : Change pass");

		/* get options */
		pressedButton=KEYPAD_getPressedKey();
		/* for solving overlapping */
		_delay_ms(400);

		/* check the pressed button */
		if(pressedButton!='-'&&pressedButton!='+')
			continue;

		/* check the Password */
		unMatchCounter=0;
		while (unMatchCounter < 3 && checkPassword() == FAILURE) {
			unMatchCounter++;
		}

		if (unMatchCounter == 3) {
			error();
			continue;
		}

		if(pressedButton=='-'){
			/* create new password */
			while(createPassword()==FAILURE);

		}else if(pressedButton=='+'){
			/* opening door lock routine */

			UART_sendByte(UART_OPEN_DOOR_FLAG);

			LCD_clearScreen();
			LCD_moveCursor(0,0);
			LCD_displayString("Door is Unlocking");

			seconds=0;
			while(seconds<15);

			LCD_clearScreen();
			LCD_displayString("Unlocked");

			while(seconds<18);

			LCD_moveCursor(0,0);
			LCD_displayString("Door is Locking");

			while(seconds<33);

		}

	}


}

void secondsCounter(void){
	seconds++;
}

void takePassword(uint8 *str){
	uint8 idx=0,pressedButton;
	while (1) {
		pressedButton = KEYPAD_getPressedKey();

		/* for solving overlapping */
		_delay_ms(400);

		if (pressedButton == ENTER_BUTTON) {
			break;
		}
		str[idx++] = pressedButton + '0';
		LCD_displayCharacter('*');
	}
}

uint8 createPassword(){
	uint8 password[5], password_confirmation[5], idx = 0;

	LCD_clearScreen();
	LCD_moveCursor(0, 0);
	LCD_displayString("plz enter pass: ");
	LCD_moveCursor(1, 0);

	/* take the pass from the user */
	takePassword(password);

	LCD_moveCursor(0, 0);
	LCD_displayString("plz re_enter the");
	LCD_moveCursor(1, 0);
	LCD_displayString("same pass: ");


	/* re-take the pass from the user */
	takePassword(password_confirmation);

	/* send two passwords to controller */
	UART_sendByte(UART_SEND_PASS_FLAG);
	for (idx = 0; idx < 5; idx++) {
		UART_sendByte(password[idx]);
	}
	for (idx = 0; idx < 5; idx++) {
		UART_sendByte(password_confirmation[idx]);
	}

	/* UART sync */
	while(UART_recieveByte()!=UART_READY);

	/* get the response of controller */
	return UART_recieveByte();
}

uint8 checkPassword(void){
	uint8 pass[5], idx=0;

	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString("plz enter pass: ");
	LCD_moveCursor(1,0);

	/* take the pass from the user */
	takePassword(pass);

	UART_sendByte(UART_CONFIRM_PASS_FLAG);
	for (idx = 0; idx < 5; idx++) {
		UART_sendByte(pass[idx]);
	}

	while(UART_recieveByte()!=UART_READY);

	return UART_recieveByte();
}

void error(void){
	UART_sendByte(UART_PASS_UNMATCH);

	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString("ERROR....");

	seconds=0;
	while(seconds<60);
}
