/*
 * DELAY.h
 *
 *  Created on: 24-May-2018
 *      Author: Gawali
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f1xx.h"



int milliseconds=0;
void delay_ms(int delay)
{

	while(milliseconds < (delay/2))
	{
	if(TIM2->SR & (TIM_SR_UIF))
	{
		milliseconds++;
		TIM2->SR &= ~(TIM_SR_UIF);

	}

	}
	milliseconds=0;
}

void delayInit()
{
	RCC-> APB1ENR |= (RCC_APB1ENR_TIM2EN);
	TIM2-> PSC = 7999;
	TIM2->CR1 |= (TIM_CR1_CEN);

	TIM2->CR1 &= ~(TIM_CR1_DIR);
	TIM2->ARR=1;
}


#endif /* DELAY_H_ */
