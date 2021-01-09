/*
 *  systick.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

/*!
 * @addtogroup systick
 * @{
 */

/******************************************************************************
 * API
 *****************************************************************************/

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x.h"
/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/
#define MAXTICK			0xFFFFFFFF

/*!
 * @brief functions init systick.
 *
 */
void SYSTICK_Init(void);

 /*!
 * @brief functions hander systick.
 *
 */
void SysTick_Handler(void);

/*!
 * @brief functions get tick.
 *
 */
uint32_t SYSTICK_Get_Tick(void);

/*!
 * @brief function to create delay.
 *
 */
void SYSTICK_Delay_ms(uint32_t time_ms);

#endif /*_SYSTICK_H_*/