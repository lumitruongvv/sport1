/*
 *  queue.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _QUEUE_H_
#define _QUEUE_H

#include "stm32f10x.h"

/******************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/
typedef struct QUEUEx_t
{
    u8 *p;
    u8  element_size;
    u8  queue_size;
    u8  count;
    u16 in;
    u16 out;
}QUEUEx_t;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void  QUEUE_Init(QUEUEx_t *q,u8* buffer,u8 queue_size, u8 element_size);
u8    QUEUE_Push(QUEUEx_t *q,u8* data);
u8    QUEUE_Get(QUEUEx_t *q, u8* buffer);
u8    QUEUE_Empty(QUEUEx_t *q);
u8    QUEUE_Count(QUEUEx_t *q);

#endif /*_QUEUE_H*/