/*
 *      irfapp_main.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "power_main.h"
#include "power.h"
#include "stddef.h"
#include "string.h"
#include "xor.h"

volatile u8 checkconnect = 0;
volatile u8 startrun = 0;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
static void POWER_SendFirstTime(u8 type,u8 *buff, u8 len);

static void POWER_SendFirstTime1(u8 type,u8 *buff, u8 len);

static void POWER_SendFirstTime2(u8 type,u8 *buff, u8 len);

static void POWER_DeviceAnnounce(u8 type,u8 *buff, u8 len);

static void POWER_CheckConnect(u8 type,u8 *buff, u8 len);

static void POWER_StartRun(u8 type,u8 *buff, u8 len);

static void POWER_StopRun(u8 type, u8 *buff, u8 len);

static void POWER_UpDownFloor(u8 type, u8 *buff, u8 len);

static void POWER_GetStateMotor(u8 type, u8 *buff, u8 len);

static void POWER_GetStateFloor(u8 type, u8 *buff, u8 len);

static void POWER_SetSpeedMotor(u8 type, u8 *buff, u8 len);

static void POWER_GetAllState(u8 type, u8 *buff, u8 len);

static const POWER_ComandInfo_t powerListCommand[]=
{
    {SEND_FIRST_TIME        ,POWER_SendFirstTime},
    {SEND_FIRST_TIME_1      ,POWER_SendFirstTime1},
    {SEND_FIRST_TIME_2      ,POWER_SendFirstTime2},
    {DEVICE_ANNOUNCE        ,POWER_DeviceAnnounce},
    {CHECK_CONNECT          ,POWER_CheckConnect},
    {START_RUN              ,POWER_StartRun},
    {STOP_RUN               ,POWER_StopRun},
    {UP_DOW_FLOOR           ,POWER_UpDownFloor},
    {GET_STATE_MOTOR        ,POWER_GetStateMotor},
    {GET_STATE_FLOOR        ,POWER_GetStateFloor},
    {SET_SPEED_MOTOR        ,POWER_SetSpeedMotor},
    {GET_ALL_STATE          ,POWER_GetAllState}
};

/**
 * @func   POWER_CheckCommandExistAndExecutes
 * @brief  None
 * @param  
 * @retval None
 */
void POWER_CheckCommandExistAndExecutes(u8 command, u8 type, u8* buff, u8 length)
{
    int i;
    for(i = 0; i<sizeof(powerListCommand)/sizeof(POWER_ComandInfo_t);i++)
    {
        if(command == powerListCommand[i].cmdId)
        {
            if(powerListCommand[i].cmdHandle != NULL)
            {
                powerListCommand[i].cmdHandle(type, buff, length);
            }
        }
    }
}


/**
 * @func   POWER_SendFirstTime
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_SendFirstTime(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   POWER_SendFirstTime1
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_SendFirstTime1(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   POWER_SendFirstTime2
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_SendFirstTime2(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   POWER_DeviceAnnounce
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_DeviceAnnounce(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   POWER_CheckConnect
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_CheckConnect(u8 type,u8 *buff, u8 len)
{
    checkconnect = 1;
}

/**
 * @func   POWER_StartRun
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_StartRun(u8 type,u8 *buff, u8 len)
{
    startrun = 1;
}

/**
 * @func   POWER_StopRun
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_StopRun(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   POWER_UpDownFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_UpDownFloor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   POWER_GetStateMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_GetStateMotor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   POWER_GetStateFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_GetStateFloor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   POWER_SetSpeedMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_SetSpeedMotor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   POWER_GetAllState
 * @brief  None
 * @param  
 * @retval None
 */
static void POWER_GetAllState(u8 type, u8 *buff, u8 len)
{

}