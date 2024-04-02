# Door Locker Security System

This project implements a door locking system using two ATmega32 microcontrollers. It follows a layered architecture model, with one microcontroller serving as the Human Machine Interface (HMI_ECU) and the other as the Control ECU (CONTROL_ECU).
# System Features:
HMI_ECU (Human Machine Interface): Responsible for user interaction via a 2x16 LCD and a 4x4 keypad.
Control_ECU: Handles all processing and decisions, including password checking, door unlocking, and system alarm activation. It interfaces with EEPROM, a buzzer, and a DC motor.
System Allows users to set and change passwords through the HMI.
Supports unlocking the door and changing passwords.
Activates an alarm if incorrect passwords are entered consecutively.
Utilizes UART communication between ECUs for password exchange.
# Drivers Implemented:
GPIO Driver
LCD Driver (2x16 LCD)
Keypad Driver (4x4 Keypad)
DC Motor Driver
EEPROM Driver
I2C Driver
UART Driver
Timer Driver (TIMER1)
Buzzer Driver
# Requirements:
Both ECUs use the same GPIO, UART, and Timer drivers.
Different drivers are implemented for specific components like LCD, keypad, DC motor, EEPROM, I2C, and buzzer.
Configuration structures are used for initializing drivers, with specific configurations tailored to each driver's requirements.
# Notes:
This project was developed as part of a microcontroller course and is designed for educational purposes.
The code is structured to demonstrate good software design practices such as modularization and abstraction.
Feel free to adjust the description as needed to b.
