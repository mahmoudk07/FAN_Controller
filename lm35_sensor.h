/****************************************************
* [Module]: LM35 Temperature Sensor
* [File Name] : lm35_sensor.h
* [Description] : Header file for LM35 Temperature sensor
* [Author] : Mahmoud Khaled
* [Date] : 2/10/2022
****************************************************/
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"
/*****************************************************
*                    Definitions                     *
*****************************************************/

#define SENSOR_CHANNEL_ID 2
#define SENSOR_MAX_VOLT_VALUE 1.5
#define SENSOR_MAX_TEMPERATURE 150

/**********************************************************
*                Functions Prototypes                     *
**********************************************************/

/**
* [Function Name]: LM35_GetTemperature
* [Description]: Get Temperature value depends on Digital value output from ADC and ADC Ref Voltage
* [Argument]: No arguments
* [Returns]: uint8--> Returns Temperature value Measured From 0 to 150
**/
uint8 LM35_GetTemperature();

#endif /* LM35_SENSOR_H_ */
