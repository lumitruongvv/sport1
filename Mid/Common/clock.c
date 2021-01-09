/*
 *  clock.c
 *
 *  Created on: Dec 25, 2020
 *  Author: Truong VV
 */

#include "clock.h"
#include "stm32f10x_rcc.h"

/**
 * @func   CLOCK_Config
 * @brief  None
 * @param  
 * @retval None
 */
void CLOCK_Config(void)
{
    /* GPIOD Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    /* GPIOA Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    /* GPIOB Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}