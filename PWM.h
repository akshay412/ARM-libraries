/*
 * PWM.h
 *
 *  Created on: 23-May-2018
 *      Author: Gawali
 */

#ifndef PWM_H_
#define PWM_H_


/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f1xx.h"
#include "GPIO.h"

//PWM PIN IS PA8
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3




void pwmInit(int Timer,int channel)
{

	if(Timer == TIMER1)
	{
		RCC-> APB2ENR |= (RCC_APB2ENR_IOPAEN) | (RCC_APB2ENR_AFIOEN)|(RCC_APB2ENR_TIM1EN); //Enable Clock
		GPIOA->CRH |= (11<< ((4*channel)-4)); //MODE=Output
		GPIOA->CRH |=(1<<((4*channel)-1));    //... ALternate pushpull
		GPIOA->CRH &= ~(1<<((4*channel)-2));  //...



		TIM1->PSC =3; //Prescaler

//		TIM1-> ARR = 8*period; // period of pulse
		TIM1-> ARR = 2000;




		TIM1->CR1 |= (TIM_CR1_CEN); //counter enable

		TIM1->CCER &= ~(1<<((4*channel)-3)); //Clock polarity = 0 for active high
		TIM1->CCER |= (1<<(4*(channel-1))); //Output compare enable

		TIM1->BDTR |=(TIM_BDTR_MOE); //main output enable

		TIM1->EGR |= (TIM_EGR_UG); //required to clear counter

		if(channel == 1 )
		{
			TIM1->CCMR1 |= (TIM_CCMR1_OC1M_2)|(TIM_CCMR1_OC1M_1)|((TIM_CCMR1_OC1PE)); //...PWM mode selection and preload enable
			TIM1->CCMR1 &= ~((TIM_CCMR1_OC1M_0));						//...
		}
		else if(channel == 2)
		{
			TIM1->CCMR1 |= (TIM_CCMR1_OC2M_2)|(TIM_CCMR1_OC2M_1)|((TIM_CCMR1_OC2PE)); //...PWM mode selection and preload enable
			TIM1->CCMR1 &= ~((TIM_CCMR1_OC2M_0));
		}
		else if(channel ==  3)
		{
			TIM1->CCMR2 |= (TIM_CCMR2_OC3M_2)|(TIM_CCMR2_OC3M_1)|((TIM_CCMR2_OC3PE)); //...PWM mode selection and preload enable
			TIM1->CCMR2 &= ~((TIM_CCMR2_OC3M_0));
		}
		else if(channel == 4)
		{
			TIM1->CCMR2 |= (TIM_CCMR2_OC4M_2)|(TIM_CCMR2_OC4M_1)|((TIM_CCMR2_OC4PE)); //...PWM mode selection and preload enable
			TIM1->CCMR2 &= ~((TIM_CCMR2_OC4M_0));						//...
		}

	}
	//..............................



	//......................

	//......................
}

void pwmWrite(int Timer, int channel,int dutycycle)
{

	if(dutycycle>= TIM1->ARR)
	{
		dutycycle=TIM1->ARR;
	}
	else if(dutycycle<=0)
	{
		dutycycle=0;
	}


	if(Timer==TIMER1)
	{
		if(channel==1)
		{
			TIM1-> CCR1 = dutycycle;
		}
		else if(channel==2)
		{
			TIM1-> CCR2 = dutycycle;
		}
		else if(channel==3)
		{
			TIM1-> CCR3 = dutycycle;
		}
		else if(channel==4)
		{
			TIM1-> CCR4 = dutycycle;
		}

	}









}

void pwmWritePercent(int Timer,int channel ,int dutycycle_percent)
{

	if(dutycycle_percent>=100)
	{
		dutycycle_percent=100;
	}
	else if(dutycycle_percent<=0)
	{
		dutycycle_percent=0;
	}

	if(Timer==TIMER1)
	{
		if(channel==1)
		{
			TIM1-> CCR1 = (((dutycycle_percent)*(TIM1->ARR))/(100));
		}
		if(channel==2)
		{
			TIM1-> CCR2 = (((dutycycle_percent)*(TIM1->ARR))/(100));
		}
		if(channel==3)
		{
			TIM1-> CCR3 = (((dutycycle_percent)*(TIM1->ARR))/(100));
		}
		else if(channel==4)
		{
			TIM1-> CCR4 = (((dutycycle_percent)*(TIM1->ARR))/(100));
		}

	}






}


#endif /* PWM_H_ */
