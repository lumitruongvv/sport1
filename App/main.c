/*
 * Copyright (c) 2021
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: xxx $
 * Last Changed:     $Date: xxx $
 */

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "stm32f10x_usart.h"
#include "systick.h"
#include "clock.h"
#include "uart.h"
#include "nvic.h"
#include "bluetooth.h"

/******************************************************************************/
/*                          PRIVATE FUNCTIONS DECLERATION                     */
/******************************************************************************/

/**
 * @func   main
 * @brief  None
 * @param  
 * @retval None
 */
int main(void)
{
    SystemInit();
	SYSTICK_Init();
    BLUETOOTH_Init();
    NVIC_Config_Init();
	while(1)
    {
	}
}