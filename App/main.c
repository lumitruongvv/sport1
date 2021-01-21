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
#include "softuart.h"
#include "nvic.h"
#include "bluetooth.h"
#include "power.h"

extern volatile u8 ble_SetLock, checkconnect;

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
    POWER_Init();
    Softuart_Config(BAUDRATE_1200);
    NVIC_Config_Init();
	while(1)
    {
        // BLUETOOTH_Proc();
        // POWER_Proc();
        // if(ble_SetLock == 1)
        // {
        //     ble_SetLock = 0;
        //     BLUETOOTH_Send(buff, sizeof(buff));
        // }
        // if(checkconnect == 1)
        // {
        //     checkconnect = 0;
        //     POWER_Send(buff, sizeof(buff));
        // }
	}
}