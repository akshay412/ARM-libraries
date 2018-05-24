/*
 * GPIO.h
 *
 *  Created on: 23-May-2018
 *      Author: akshay
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f1xx.h"
#define LOW				0
#define HIGH 			1
#define PORTA			0
#define PORTB 			1
#define PORTC			2
#define INPUT			0
#define OUTPUT			1
#define ALT_FN			2
#define INPUT_PULLUP 	3

void pinMode(int port,int pinNumber,int state){
	if(port == PORTA){
		RCC ->APB2ENR |= RCC_APB2ENR_IOPAEN;
		if(pinNumber/8==1){		//HIGH
			if(state==INPUT){
				GPIOA ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOA ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOA ->CRH &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==OUTPUT){
				GPIOA ->CRH |=	(11<<(pinNumber%8)*4);
				GPIOA ->CRH &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOA ->CRH |=(11<<(pinNumber%8)*4);
				GPIOA ->CRH |=(1000<<(pinNumber%8)*4);
				GPIOA ->CRH &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==INPUT_PULLUP){
				GPIOA ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOA ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOA ->CRH &= ~(100<<(pinNumber%8)*4);
				GPIOA ->BSRR |= 1<<(pinNumber);
			}

		}
		else if(pinNumber/8==0){	//LOW
			if(state==INPUT){
				GPIOA ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOA ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOA ->CRL &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==OUTPUT){
				GPIOA ->CRL |=	(11<<(pinNumber%8)*4);
				GPIOA ->CRL &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOA ->CRL |=(11<<(pinNumber%8)*4);
				GPIOA ->CRL |=(1000<<(pinNumber%8)*4);
				GPIOA ->CRL &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==INPUT_PULLUP){
				GPIOA ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOA ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOA ->CRL &= ~(100<<(pinNumber%8)*4);
				GPIOA ->BSRR |= 1<<(pinNumber);
			}
		}
	}
	else if(port == PORTB){
		RCC ->APB2ENR |= RCC_APB2ENR_IOPBEN;
		if(pinNumber/8==1){		//HIGH
			if(state==INPUT){
				GPIOB ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOB ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOB ->CRH &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==OUTPUT){
				GPIOB ->CRH |=	(11<<(pinNumber%8)*4);
				GPIOB ->CRH &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOB ->CRH |=(11<<(pinNumber%8)*4);
				GPIOB ->CRH |=(1000<<(pinNumber%8)*4);
				GPIOB ->CRH &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==INPUT_PULLUP){
				GPIOB ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOB ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOB ->CRH &= ~(100<<(pinNumber%8)*4);
				GPIOB ->BSRR |= 1<<(pinNumber);
			}
		}
		else if(pinNumber/8==0){	//LOW
			if(state==INPUT){
				GPIOB ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOB ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOB ->CRL &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==OUTPUT){
				GPIOB ->CRL |=	(11<<(pinNumber%8)*4);
				GPIOB ->CRL &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOB ->CRL |=(11<<(pinNumber%8)*4);
				GPIOB ->CRL |=(1000<<(pinNumber%8)*4);
				GPIOB ->CRL &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==INPUT_PULLUP){
				GPIOB ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOB ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOB ->CRL &= ~(100<<(pinNumber%8)*4);
				GPIOB ->BSRR |= 1<<(pinNumber);
			}
		}
	}

	else if(port == PORTC){

		RCC ->APB2ENR |= RCC_APB2ENR_IOPCEN;
		if(pinNumber/8==1){		//HIGH
			if(state==INPUT){
				GPIOC ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOC ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOC ->CRH &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==OUTPUT){
				GPIOC ->CRH |=	(11<<(pinNumber%8)*4);
				GPIOC ->CRH &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOC ->CRH |=(11<<(pinNumber%8)*4);
				GPIOC ->CRH |=(1000<<(pinNumber%8)*4);
				GPIOC ->CRH &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==INPUT_PULLUP){
				GPIOC ->CRH &= ~(11<<(pinNumber%8)*4);
				GPIOC ->CRH |= 	(1000<<(pinNumber%8)*4);
				GPIOC ->CRH &= ~(100<<(pinNumber%8)*4);
				GPIOC ->BSRR |= 1<<(pinNumber);

			}
		}
		else if(pinNumber/8==0){	//LOW
			if(state==INPUT){
				GPIOC ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOC ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOC ->CRL &= ~(100<<(pinNumber%8)*4);
			}
			else if(state==OUTPUT){
				GPIOC ->CRL |=	(11<<(pinNumber%8)*4);
				GPIOC ->CRL &= ~(1100<<(pinNumber%8)*4);
			}
			else if(state==ALT_FN){
				GPIOC ->CRL |=(11<<(pinNumber%8)*4);
				GPIOC ->CRL |=(1000<<(pinNumber%8)*4);
				GPIOC ->CRL &= ~(100<<(pinNumber%8)*4);

			}
			else if(state==INPUT_PULLUP){
				GPIOC ->CRL &= ~(11<<(pinNumber%8)*4);
				GPIOC ->CRL |= 	(1000<<(pinNumber%8)*4);
				GPIOC ->CRL &= ~(100<<(pinNumber%8)*4);
				GPIOC ->BSRR |= 1<<(pinNumber);

			}
		}
	}
}

void digitalWrite(int port,int pinNumber, int state){
	if(port == PORTA){
		if(state == HIGH){
			GPIOA ->BSRR |= (1<<pinNumber);
		}
		else if(state == LOW){
			GPIOA ->BSRR |=(1<<(pinNumber+16));
		}
	}

	else if(port == PORTB){
		if(state == HIGH){
			GPIOB ->BSRR |= (1<<pinNumber);
		}
		else if(state == LOW){
			GPIOB ->BSRR |=(1<<(pinNumber+16));
		}
	}

	else if(port == PORTC){
		if(state == HIGH){
			GPIOC ->BSRR |= (1<<pinNumber);
		}
		else if(state == LOW){
			GPIOC ->BSRR |=(1<<(pinNumber+16));
		}
	}
}

int digitalRead(int port,int pinNumber){
	if(port == PORTA){
		if(GPIOA->IDR & 1<<pinNumber){
			return 1;
		}
		else if(!(GPIOA->IDR & 1<<pinNumber)){
			return 0;
		}
	}
	else if(port == PORTB){
		if(GPIOB->IDR & 1<<pinNumber){
			return 1;
		}
		else if(!(GPIOB->IDR & 1<<pinNumber)){
			return 0;
		}
	}
	else if(port == PORTC){
		if(GPIOC->IDR & 1<<pinNumber){
			return 1;
		}
		else if(!(GPIOC->IDR & 1<<pinNumber)){
			return 0;
		}
	}
}






#endif /* GPIO_H_ */
