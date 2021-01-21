#ifndef _SOFTUART_H_
#define _SOFTUART_H_

#include "stm32f10x.h"

#define BAUDRATE_1200   104   
#define setlow()        GPIO_ResetBits(GPIOA, GPIO_Pin_11);
#define sethigh()       GPIO_SetBits(GPIOA, GPIO_Pin_11);

void Softuart_Handtick(void);

uint32_t Softuart_Gettick(void);

void Softuart_Config(uint32_t Baudrate);

void Softuart_SendByte(uint8_t byte);

void Softuart_send_frame(uint8_t startbyte, uint8_t addressbyte,
                                    uint8_t databyte, uint8_t stopbyte);

void Softuart_SendData(uint8_t* buff, uint8_t length);

#endif /*_SOFTUART_H_*/