/*
 * main.c
 *
 *  Created on: Dec 18, 2023
 *      Author: jaina
 */
#include "main.h"
#include "stm32f4xx_hal.h"
#include <string.h>

void GPIO_Init(void);

void Error_handler(void);
void TIMER10_Init(void);
void SystemClock_Config(void);
TIM_HandleTypeDef htimer10;




int main(void)
{


	HAL_Init();

	SystemClock_Config();
	GPIO_Init();
	TIMER10_Init();
	//Start the timer
	HAL_TIM_Base_Start(&htimer10);
	while(1)
	{
		while( ! (TIM10->SR & TIM_SR_UIF) );
		TIM10->SR = 0;
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
	}




}


void GPIO_Init()
{
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_InitTypeDef ledgpio;
	ledgpio.Pin = GPIO_PIN_14;
	ledgpio.Mode = GPIO_MODE_OUTPUT_PP;
	ledgpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD,&ledgpio);
}

void TIMER10_Init(void)
{
	htimer10.Instance = TIM10;
	htimer10.Init.Prescaler = 24;
	htimer10.Init.Period = 64000-1;
	HAL_TIM_Base_Init(&htimer10);

}

void SystemClock_Config()
{

}


void Error_handler(void)
{
	//Blink some LEDs or whatever
}
