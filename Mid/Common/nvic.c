/*
 *  nvic.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "nvic.h"

/*!
 * @brief functions config init.
 *
 */
void NVIC_Config_Init(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    /* Configure the NVIC Preemption Priority Bits */  
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    
    /* Enable the USARTy Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}