/*
 * UART.h
 *
 *  Created on: 14-May-2018
 *      Author: Gawali
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f1xx.h"

void delay(int Moment)
{
volatile int i, j;

for (i=0; i < Moment; i++) {
j ++;
}
}

void UartInit(int baud){
    RCC		->APB2ENR |= RCC_APB2ENR_IOPAEN;
    GPIOA	->CRL |= GPIO_CRL_MODE2_1;
    GPIOA	->CRL |= GPIO_CRL_CNF2_1;
    GPIOA	->CRL |= GPIO_CRL_MODE3;
    GPIOA	->CRL |= GPIO_CRL_CNF3_0;

 	double usartDiv;
	int divMantissa,op,divFraction;
	usartDiv=500000.00/baud;
	divMantissa=(int)(usartDiv);
	divFraction=(int)(16*(usartDiv - divMantissa)+0.5);
	op =(16 * divMantissa)+ divFraction;	   


    RCC	   ->APB1ENR |= RCC_APB1ENR_USART2EN;
    USART2 ->CR1 |= USART_CR1_UE;
	USART2 ->CR1 &= ~USART_CR1_M;
	USART2 ->CR2 &= ~USART_CR2_STOP;
	USART2 ->BRR=op;
	USART2 ->CR1 |= USART_CR1_TE;
}


unsigned char UartReceive(void)
{
	while(!(USART2->SR & (USART_SR_RXNE)));
	return (USART2->DR);
}

void UartTransmit(int a){
	int size=0,hex=0;
	int x=a;
	while(a!=0){
		a=a/10;
		size++;
	}
	int arr[size];

	for(int i=size-1;i>=0;i--){
		arr[i]=x%10;
		x=x/10;
	}
	for(int i=0;i<size;i++){
		hex=arr[i]+48;
		USART2 ->DR = hex;
		while(!(USART2->SR & (USART_SR_TXE)));

		delay(1000);
	}


}
void UartTransmitln(int a){
	int size=0,hex=0;
	int x=a;
	while(a!=0){
		a=a/10;
		size++;
	}
	int arr[size];

	for(int i=size-1;i>=0;i--){
		arr[i]=x%10;
		x=x/10;
	}
	for(int i=0;i<size;i++){
		hex=arr[i]+48;
		USART2 ->DR = hex;
		while(!(USART2->SR & (USART_SR_TXE)));

		delay(1000);
	}
	USART2 -> DR=0x0A;
	while(!(USART2->SR & (USART_SR_TXE)));

}


void TempUartTransmit(int data)
{

	//while(!(USART1->SR & (USART_SR_TC)));

	USART2->DR=data;
	while(!(USART2->SR & (USART_SR_TXE)));
}
void UartTransmitString(unsigned char* string)
{
	while(*string!='\0')
	TempUartTransmit(*string++);
}



#endif /* UART_H_ */
