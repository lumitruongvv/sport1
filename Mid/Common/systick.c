/*
 *  systick.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "systick.h"

/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/
static uint32_t tick;

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/* FUNCTION ********************************************************************
 *
 * Function Name : SYSTICK_Init
 * Description   : 
 *
 * END ************************************************************************/
void SYSTICK_Init(void)
{
    SysTick_Config(SystemCoreClock/1000);
}

/* FUNCTION ********************************************************************
 *
 * Function Name : SysTick_Handler
 * Description   : Systick handler function
 *
 * END ************************************************************************/
void SysTick_Handler(void)
{
  	tick++;
}
/* FUNCTION ********************************************************************
 *
 * Function Name : SYSTICK_Get_Tick
 * Description   : Tick get function
 *
 * END ************************************************************************/
uint32_t SYSTICK_Get_Tick(void)
{
  	return tick;
}
/* FUNCTION ********************************************************************
 *
 * Function Name : SYSTICK_Delay_ms
 * Description   : Delay function
 *
 * END ************************************************************************/
void SYSTICK_Delay_ms(uint32_t time_ms)
{
  	static uint32_t t0, t1;
	t0 = SYSTICK_Get_Tick();
	t1 = SYSTICK_Get_Tick();
	if(t0 < MAXTICK - time_ms)
	{
	  	while(t1 - t0 < time_ms)
		{
		  	t1 = SYSTICK_Get_Tick();
		}
		return;
	}else
	{
	  	if(t1 > time_ms)
		{
		  	while(t1 > time_ms)
			{
			  	t1 = SYSTICK_Get_Tick();
			}
			while(MAXTICK - t0 + t1 < time_ms)
			{
			  	t1 = SYSTICK_Get_Tick();
			}
			return;
		}else
		{
		  	while(MAXTICK - t0 + t1 < time_ms)
			{
			  	t1 = SYSTICK_Get_Tick();
			}
			return;
		}
	}
}