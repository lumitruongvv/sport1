/*
 *  bluetooth.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _BLUETOOTH_H_
#define _BLUETOOTH_H_

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x.h"

/******************************************************************************/
/*                              DEFINE                                        */
/******************************************************************************/

#define BLUETOOTH_COMMAND_MAX_LENGH 50
#define BLUETOOTH_COMMAND_MAX_SIZE  3
#define BLUETOOTH_COMMAND_HEADER_SIZE 4
#define BLUETOOTH_COM               USART1
#define BLUETOOTH_BAUDRATE          57600


typedef struct BLUETOOTH_Command_t
{
    u8 command;
    u8 type;
    u8 sequence;
    u8 length;
    u8 buff[BLUETOOTH_COMMAND_MAX_LENGH];
} BLUETOOTH_Command_t;

void BLUETOOTH_Init(void);
void BLUETOOTH_CallBackHandle(USART_TypeDef* USARTx);
void BLUETOOTH_Proc(void);
void BLUETOOTH_Send(u8* buff, u8 length);

#endif /*_BLUETOOTH_H_*/