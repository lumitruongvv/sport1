/*
 *  power.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _POWER_H_
#define _POWER_H_

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x.h"

/******************************************************************************/
/*                              DEFINE                                        */
/******************************************************************************/

#define POWER_COMMAND_MAX_LENGH 5
#define POWER_COMMAND_MAX_SIZE  2
#define POWER_COMMAND_HEADER_SIZE 4
#define POWER_COM               USART2
#define POWER_BAUDRATE          1200


typedef struct POWER_Command_t
{
    u8 command;
    u8 type;
    u8 sequence;
    u8 length;
    u8 buff[POWER_COMMAND_MAX_LENGH];
} POWER_Command_t;

void POWER_Init(void);
void POWER_CallBackHandle(USART_TypeDef* USARTx);
void POWER_Proc(void);
void POWER_Send(u8* buff, u8 length);

#endif /*_POWER_H_*/