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
extern volatile u8 startrun;
uint8_t step = 0;
uint8_t checkConnect[]  = {0x20, 0xB0, 0x00, 0x01, 0x20, 0xB1};
uint8_t startRun[]      = {0x30, 0xB0, 0x00, 0x01, 0x30, 0xB1};
uint8_t stopRun[]       = {0x40, 0xB0, 0x00, 0x01, 0x40, 0xB1};
uint8_t updownFloor[]   = {0x50, 0xB0, 0x00, 0x01, 0x50, 0xB1};
uint8_t getStateMotor[] = {0x70, 0xB0, 0x00, 0x01, 0x70, 0xA2};
uint8_t getStateFloor[] = {0x73, 0xB0, 0x00, 0x01, 0x73, 0xA6};
uint8_t setSpeedMotor[] = {0x80, 0xB0, 0x00, 0x01, 0x80, 0x2A};
uint8_t getAllState[]   = {0x90, 0xB0, 0x00, 0x02, 0x90, 0x71, 0x63};
uint8_t resetDevice[]   = {0x0F, 0xB0, 0x00, 0x01, 0x0F, 0xA5};

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
        switch (step)
        {
        case 0:
            POWER_Send(checkConnect, sizeof(checkConnect));
            break;
        case 1:
            POWER_Send(startRun, sizeof(startRun));
            break;
        case 2: 
            break;
        default:
            break;
        }
        POWER_Proc();
        if(checkconnect == 1)
        {
            checkconnect = 0;
            step = 1;
        }else if(startrun == 1)
        {
            startrun = 0;
            step = 2;
        }
        SYSTICK_Delay_ms(500);
	}
}