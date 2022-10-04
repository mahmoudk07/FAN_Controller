/****************************************************
* [File Name] : Application.c
* [Description] : Application of Fan_Controller
* [Author] : Mahmoud Khaled
* [Date] : 2/10/2022
****************************************************/

#include "lcd.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "pwm.h"
int main(void){
	uint8 temp; // declare a variable temp to take temp from sensor //
	// Initialize LCD Driver //
	ADC_ConfigType ADC_Configuration = {3,3};
	LCD_init();
	// Initialize ADC Driver //
	ADC_init(&ADC_Configuration);
	// Initialize Motor Driver //
	DCMotor_init();
	// Move Cursor to specific location in LCD Display //
	LCD_moveCursor(0,4);
	// Display String Exist at all time when LCD initialized //
	LCD_displayString("FAN IS ");
	// Move Cursor to specific location in LCD Display //
	LCD_moveCursor(1,4);
	// Display String Exist at all time when LCD initialized //
	LCD_displayString("Temp =    C");
	while(1){
		// Read Temperature value From Temperature sensor //
		temp = LM35_GetTemperature();
		// Check if Temp less than 30 ---> DC MOTOR OFF and Display State of FAN(OFF)
		if(temp < 30){
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
			DCMotor_rotate(1,0);
		}
		else{
			// Move Cursor to Specific Position in LCD display //
			LCD_moveCursor(0,11);
			// Display State of FAN (ON) when Temp greater than 30 //
			LCD_displayString("ON ");
			if(temp >= 30 && temp < 60)
			{
				// Motor will rotate Clock wise with 25% Duty Cycle //
				DCMotor_rotate(1,25);
			}
			else if(temp >= 60 && temp < 90)
			{
				// Motor will rotate Clock wise with 50% Duty Cycle //
				DCMotor_rotate(1,50);
			}
			else if(temp >= 90 && temp < 120)
			{
				// Motor will rotate Clock wise with 75% Duty Cycle //
				DCMotor_rotate(1,75);
			}
			else if(temp >= 120)
			{
				// Motor will rotate Clock wise with 100% Duty Cycle //
				DCMotor_rotate(1,100);
			}
		}
		// Move Cursor to Specific Position in LCD display //
		LCD_moveCursor(1,11);
		// Check if Number consist of 3 digits //
		if(temp >= 100)
		{
			// It will be Printed Normally on LCD Display //
			LCD_integerToString(temp);
		}
		else
		{
			// If Number Consists of 2 Digits //
			// If Sensor Reach to value of 3 digits and after some duration it return back to read value of 2-digits //
			// Here digit-3 will still Printed on LCD Screen so, To avoid that it will Print a space instead of that Digit
			LCD_integerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}
