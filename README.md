# FAN_Controller
### Description:
#### This is Fan controller system that controlled by ATmega32 microcontroller with the help of some Peripherals.
#### The Fan is turned ON or OFF according to the temperature
#### ********************************************************
### Peripherls using in The Project:
#### ADC: Analog to digital convertor that take analog signal from LM35 temperature sensor and convert it to Digital value and Return this value to LM35 sensor Driver to use this digital value in Temperature equation.
#### LM35 Sensor: Convert Physical quantatity(Temperature) to voltage signal and send it to ADC to convert this signal to digital levels(Sampling)
#### DC Motor: It's speed depends on the value of Temperature and controlled by PWM Driver, Direction is assumed to be with Clock-wise.
#### PWM Driver: PWM signal is generated by using Timer0 with Fast PWM Mode 
#### GPIO driver: Control Pins&Ports direction(Input/output) and write LOGIC(High/Low) at Specific Pin in the Required Port or at Port itself 
