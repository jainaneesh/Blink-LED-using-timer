/*
 * it.c
 *
 *  Created on: Dec 18, 2023
 *      Author: jaina
 */
#include "main.h"
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
