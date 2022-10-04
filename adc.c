 /******************************************************************************
 * [Module]: ADC Driver
 * [File Name]: adc.c
 * [Description]: Source file for the ATmega32 ADC driver
 * [Author]: Mahmoud Khaled
 * [Date]: 2/10/2022
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * [Function Name]: ADC_init
 * [Description]: Initialize ADC Driver with Required Reference Voltage and Pre-scaler
 * [Arguments]: Pointer to Structure of Type ADC_ConfigType to determine which Pre-scaler and Reference voltage ADC
 *              Will Operate
 * [Returns]: No Return Type
 */
void ADC_init(const ADC_ConfigType* config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = Required Ref Voltage depends on Member in ADC_ConfigType structure
	 * ADLAR   = 8-bits of ADC output stored in ADC Lower Register and another 2-bits stored in ADC Higher Register
	 * MUX4:0  = initialized as channel 0 (0x00000)
	 */
	ADMUX = (ADMUX & 0x3F) | ((config_Ptr->Ref_Volt)<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1 << ADEN);
	ADCSRA = (ADCSRA & 0xF8) | (config_Ptr->Prescaler);
}

/* [Function Name]: ADC_readChannel
 * [Description]: This Function Responsible for read analog signal from Sensor that connected on Argument channel
 * [Arguments]: uint8 channel_num --> Take Channel that sensor connected on it
 * [Returns]: uint16 ---> 10-bits data of ADC (Digital value after converted)
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion of ADC write LOGIC 1 on this bit */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait until ADC finish Conversion ---> Flag will be 1 (Polling method) */
	SET_BIT(ADCSRA,ADIF); /* Clear ADC interrupt Flag after Conversion */
	return ADC; /* Read the digital value from the data register */
}
