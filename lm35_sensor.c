/****************************************************
* [Module]: LM35 Temperature Sensor
* [File Name] : lm35_sensor.c
* [Description] : Source file for LM35 Temperature sensor
* [Author] : Mahmoud Khaled
* [Date] : 2/10/2022
****************************************************/
#include "lm35_sensor.h"
#include "adc.h"

/***********************************************************
*                Functions Definitions                     *
***********************************************************/
/**
* [Function Name]: LM35_GetTemperature
* [Description]: Get Temperature value depends on Digital value output from ADC and ADC Ref Voltage
* [Argument]: No arguments
* [Returns]: uint8--> Returns Temperature value Measured From 0 to 150
**/
uint8 LM35_GetTemperature(){
	uint8 temp_value = 0 ;
	uint16 adc_value = 0 ;

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}
