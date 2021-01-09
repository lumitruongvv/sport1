/*
 *  uart.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _UART_H_
#define _UART_H_

/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/
#include "stm32f10x.h"
#include "stddef.h"

/******************************************************************************/
/*                              DEFINE                                        */
/******************************************************************************/

typedef void (*type_UartCallBackInit)(USART_TypeDef*);

#define UART1_GPIO           GPIOA
#define UART1_RxPin          GPIO_Pin_10
#define UART1_TxPin          GPIO_Pin_9
#define UART1_GPIO_CLK       RCC_APB2Periph_GPIOA
#define UART1_CLK            RCC_APB2Periph_USART1

#define UART2_GPIO           GPIOA
#define UART2_RxPin          GPIO_Pin_3
#define UART2_TxPin          GPIO_Pin_2
#define UART2_GPIO_CLK       RCC_APB2Periph_GPIOA
#define UART2_CLK            RCC_APB1Periph_USART2

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void UART_PinInit(USART_TypeDef* USARTx);

void UART_ClockInit(USART_TypeDef* USARTx);

void UART_Init(USART_TypeDef* USARTx, u32 baudrate, u16 mode);

void UART_CallBackInit(USART_TypeDef* USARTx, type_UartCallBackInit pHandle);

void UART_SendData(USART_TypeDef* USARTx, u8* buff, u8 len);

u8 UART_GetData(USART_TypeDef* USARTx);

#endif /*_UART_H_*/