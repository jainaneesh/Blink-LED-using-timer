/*
 * msp.c
 *
 *  Created on: Dec 18, 2023
 *      Author: jaina
 */
#include "stm32f4xx_hal.h"
#include "main.h"
void HAL_MspInit(void)
{
	//Here we will do low level processor specific inits
	//1. Setup the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16;
	//3. Configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer)
{
	//1. Enable the clock for timer10 peripheral
	__HAL_RCC_TIM10_CLK_ENABLE();

	//2. Enable IRQ of TIM10
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

	//3. Setup the priority for TIM1_UP_TIM10_IRQn
	HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn,15,0);
}
