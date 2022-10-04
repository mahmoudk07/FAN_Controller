 /******************************************************************************
 * [Module]: ADC Driver
 * [File Name]: adc.h
 * [Description]: Header file for the ATmega32 ADC driver
 * [Author]: Mahmoud Khaled
 * [Date]: 2/10/2022
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                      Type Definitions                                       *
 ******************************************************************************/
typedef struct {
	uint8 Ref_Volt; // This Member Specify Reference Voltage //
	uint8 Prescaler; // This Member Specify Pre-scaler of ADC //
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 ******************************************************************************/

/*
 * [Function Name]: ADC_init
 * [Description]: Initialize ADC Driver with Required Reference Voltage and Pre-scaler
 * [Arguments]: Pointer to Structure of Type ADC_ConfigType to determine which Pre-scaler and Reference voltage ADC
 *              Will Operate
 * [Returns]: No Return Type
 */
void ADC_init(const ADC_ConfigType* config_Ptr);

/* [Function Name]: ADC_readChannel
 * [Description]: This Function Responsible for read analog signal from Sensor that connected on Argument channel
 * [Arguments]: uint8 channel_num --> Take Channel that sensor connected on it
 * [Returns]: uint16 ---> 10-bits data of ADC (Digital value after converted)
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
