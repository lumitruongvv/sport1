/*
 *  delay.h
 *
 *  Created on: Dec 25, 2020
 *  Author: Truong VV
 */

#ifndef _DELAY_H_

#define _DELAY_H_

#include "stm32f10x.h"

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void Systick_Increase(void);
uint32_t Get_Time(void);
void Delay_ms(uint32_t Time_ms);
void Delay_us(uint32_t Time_us);

#endif /* _DELAY_H_*/