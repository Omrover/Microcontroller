/*
 * readAdc.c
 *
 *  Created on: Aug 19, 2025
 *      Author: Ivani
 */
#include "readAdc.h"
#include "stm32f051x8.h"

int readAdc(void){
	ADC1->CR |= ADC_CR_ADSTART; //1<<2 pg. 266 ADC start conversion
	while((ADC1->ISR&ADC_ISR_EOC)==0); //wait until end of conversion pg.247
	return ADC1->DR; //Read converted value channel 3 pg. 273
}


