/*
 *  power.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "power.h"
#include "uart.h"
#include "stm32f10x_usart.h"
#include "xor.h"
#include "queue.h"
#include "power_main.h"

QUEUEx_t powerCommandQueue;
POWER_Command_t powerCommandBuff[POWER_COMMAND_MAX_SIZE];

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/*!
 * @brief functions POWER_Init.
 *
 */
void POWER_Init(void)
{
    UART_Init(POWER_COM, POWER_BAUDRATE, USART_Mode_Tx|USART_Mode_Rx);
    UART_CallBackInit(POWER_COM, POWER_CallBackHandle);
    QUEUE_Init(&powerCommandQueue, (u8*)powerCommandBuff,\
                POWER_COMMAND_MAX_SIZE, sizeof(POWER_Command_t));
    USART_Cmd(POWER_COM, ENABLE);
}

/*!
 * @brief functions POWER_CallBackHandle.
 *
 */
void POWER_CallBackHandle(USART_TypeDef* USARTx)
{
    static u8 revByteCount = 0;
    static u8 revBuff[POWER_COMMAND_HEADER_SIZE + POWER_COMMAND_MAX_LENGH + 1];
    u8 revByte = 0;
    
    revByte = UART_GetData(USARTx);
    revBuff[revByteCount++] = revByte;
    if(revByteCount >= POWER_COMMAND_HEADER_SIZE)
    {
        if(revByteCount == POWER_COMMAND_HEADER_SIZE + revBuff[3] + 1)
        {
            if(revBuff[POWER_COMMAND_HEADER_SIZE + revBuff[3]] ==\
                XOR_Caculator(revBuff, 0, POWER_COMMAND_HEADER_SIZE + revBuff[3]))
            {
                QUEUE_Push(&powerCommandQueue, revBuff);
            }
            revByteCount = 0;
        }
    }
}

/*!
 * @brief functions POWER_Proc.
 *
 */
void POWER_Proc(void)
{
    POWER_Command_t power_command;
    if(!QUEUE_Empty(&powerCommandQueue))
    {
        QUEUE_Get(&powerCommandQueue, (u8*)&power_command);
        POWER_CheckCommandExistAndExecutes(power_command.command, \
            power_command.type, power_command.buff, power_command.length);
    }

}

/*!
 * @brief functions BLUETOOTH_Send.
 *
 */
void POWER_Send(u8* buff, u8 length)
{
    UART_SendData(POWER_COM, buff, length);
}