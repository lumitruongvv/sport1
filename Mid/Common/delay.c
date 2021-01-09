/*
 *  delay.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "delay.h"

static uint32_t Tick;

/**
 * @func   Systick_Increase
 * @brief  None
 * @param  
 * @retval None
 */
void Systick_Increase(void)
{
    Tick++;
}

/**
 * @func   Systick_Increase
 * @brief  None
 * @param  
 * @retval None
 */
uint32_t Get_Time(void)
{
    return Tick;
}

/**
 * @func   Delay_ms
 * @brief  None
 * @param  
 * @retval None
 */
void Delay_ms(uint32_t Time_ms)
{
    uint32_t temp = Time_ms*500;
    for(uint32_t i = 0; i < temp; i++)
    {
        Delay_us(1);
    }

}

/**
 * @func   Delay_us
 * @brief  None
 * @param  
 * @retval None
 */
void Delay_us(uint32_t Time_us)
{
    Tick = 0;
    while(Tick < Time_us);
}