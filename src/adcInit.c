/*
 * adcInit.c
 *
 *  Created on: Aug 19, 2025
 *      Author: Ivani
 */
#include "adcInit.h"
#include "stm32f051x8.h"

void adcInit(void){
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //Habilita el reloj de perifericos para ADC
	RCC->CR2 |= RCC_CR2_HSI14ON; //(Habilitar el reloj interno de 14Mhz)
	while((RCC->CR2&RCC_CR2_HSI14RDY)==0); //RCC->CR2&0x2 wait until clock is stable
	//Calibration
	ADC1->CR &= ~ADC_CR_ADEN; //Desabilita adc
	ADC1->CR |= ADC_CR_ADCAL; //Habilita la calibración
	while((ADC1->CR&ADC_CR_ADCAL)!=0); //Wait until calibration is done
	/////
	ADC1->CR |= ADC_CR_ADEN; //Hablita adc ya que se calibró
	while((ADC1->ISR&ADC_ISR_ADRDY)==0); //Espera por alto de bandera que se activa cuando está listo para aceptar una conversión
	ADC1->CFGR1 |= ADC_CFGR1_AUTOFF; //1<<15 pg. 267 ADC is off when not converting (Habilita el modo auto off)
	ADC1->CHSELR |= ADC_CHSELR_CHSEL3;//Selección de canal para conversión
	ADC1->SMPR |= 0x07; // sampling rate = 239.5 ADC clock cycles
}
