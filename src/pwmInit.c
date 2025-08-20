#include "pwmInit.h"
#include "stm32f051x8.h"

void pwmInit(void) {
    GPIOC->MODER |= GPIO_MODER_MODER9_1;
    GPIOC->AFR[1] |= 0x01 << GPIO_AFRH_AFSEL9_Pos;

    // Habilitar reloj de TIM 3
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    TIM3->PSC = 7+1;
    TIM3->ARR = 500;
    TIM3->CCR4 = 0;
    TIM3->CCMR2 |= 0x6000;
    TIM3->CCER |= 0x1000;
    TIM3->CR1 |= TIM_CR1_CEN;
}
