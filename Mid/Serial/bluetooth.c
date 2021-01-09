/*
 *  bluetooth.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "bluetooth.h"
#include "uart.h"
#include "stm32f10x_usart.h"
#include "xor.h"
#include "queue.h"
#include "appbluetooth_main.h"

QUEUEx_t bluetoothCommandQueue;
BLUETOOTH_Command_t bluetoothCommandBuff[BLUETOOTH_COMMAND_MAX_SIZE];

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/*!
 * @brief functions BLUETOOTH_Init.
 *
 */
void BLUETOOTH_Init(void)
{
    UART_Init(BLUETOOTH_COM, BLUETOOTH_BAUDRATE, USART_Mode_Tx|USART_Mode_Rx);
    UART_CallBackInit(BLUETOOTH_COM, BLUETOOTH_CallBackHandle);
    QUEUE_Init(&bluetoothCommandQueue, (u8*)bluetoothCommandBuff,\
        BLUETOOTH_COMMAND_MAX_SIZE, sizeof(BLUETOOTH_Command_t));
    USART_Cmd(BLUETOOTH_COM, ENABLE);
}

/*!
 * @brief functions UART_CallBackHandle.
 *
 */
void BLUETOOTH_CallBackHandle(USART_TypeDef* USARTx)
{
    static u8 revByteCount = 0;
    static u8 revBuff[BLUETOOTH_COMMAND_HEADER_SIZE + BLUETOOTH_COMMAND_MAX_LENGH + 1];
    u8 revByte = 0;
    
    revByte = UART_GetData(USARTx);
    revBuff[revByteCount++] = revByte;
    if(revByteCount >= BLUETOOTH_COMMAND_HEADER_SIZE)
    {
        if(revByteCount == BLUETOOTH_COMMAND_HEADER_SIZE + revBuff[3] + 1)
        {
            if(revBuff[BLUETOOTH_COMMAND_HEADER_SIZE + revBuff[3]] ==\
                XOR_Caculator(revBuff, 0, BLUETOOTH_COMMAND_HEADER_SIZE + revBuff[3]))
            {
                QUEUE_Push(&bluetoothCommandQueue, revBuff);
            }
            revByteCount = 0;
        }
    }
}

/*!
 * @brief functions BLUETOOTH_Proc.
 *
 */
void BLUETOOTH_Proc(void)
{
    BLUETOOTH_Command_t bluetooth_command;
    if(!QUEUE_Empty(&bluetoothCommandQueue))
    {
        QUEUE_Get(&bluetoothCommandQueue, (u8*)&bluetooth_command);
        BLE_CheckCommandExitsAndExecute(bluetooth_command.command, \
            bluetooth_command.type, bluetooth_command.buff, bluetooth_command.length);
    }

}

/*!
 * @brief functions BLUETOOTH_Send.
 *
 */
void BLUETOOTH_Send(u8* buff, u8 length)
{
    UART_SendData(BLUETOOTH_COM, buff, length);
}