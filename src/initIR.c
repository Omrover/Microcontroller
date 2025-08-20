/*
 * initIR.c
 *
 *  Created on: Aug 19, 2025
 *      Author: Ivani
 */

#include "stm32f051x8.h"
#include "initIR.h"


void initIR(){
// Inicializar TIM14
	RCC->APB1ENR|= RCC_APB1ENR_TIM14EN; // Habilitar TIM14 Clock
	TIM14->PSC = 8-1; // 8MHz -> 1MHz
	TIM14->ARR = (1000); // Set Autoreload value to 1000 us to wait
	TIM14->CR1 |= TIM_CR1_CEN; // Enable TIM14
	TIM14->DIER |= (1<<0); // Update Interrupt enable
	NVIC->ISER[0] |= (1<<19); // Interrupt Set Enable Register in NVIC
	//Nested vectored interrupt controller
}
