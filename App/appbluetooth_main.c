/*
 *  appbluetooth_main.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "appbluetooth_main.h"
#include "bluetooth.h"
#include "stddef.h"
#include "string.h"
#include "xor.h"

volatile u8 ble_SetLock = 0;

static void BLE_SendFirstTime(u8 type,u8 *buff, u8 len);
static void BLE_SendFirstTime1(u8 type,u8 *buff, u8 len);
static void BLE_SendFirstTime2(u8 type,u8 *buff, u8 len);

static void BLE_DeviceAnnounce(u8 type,u8 *buff, u8 len);

static void BLE_JoinNetworkResult(u8 type,u8 *buff, u8 len);
static void BLE_ToggleNetwork(u8 type,u8 *buff, u8 len);
static void BLE_GetNetworkInfo(u8 type,u8 *buff, u8 len);

static void BLE_ChangeLockState(u8 type,u8 *buff, u8 len);
static void BLE_FingerPrint(u8 type,u8 *buff, u8 len);
static void BLE_SetLock(u8 type,u8 *buff, u8 len);
static void BLE_GetLock(u8 type,u8 *buff, u8 len);

static void BLE_GetBatterry(u8 type,u8 *buff, u8 len);
static void BLE_ChangeLanguage(u8 type,u8 *buff, u8 len);
static void BLE_UpdateLanguage(u8 type,u8 *buff, u8 len);

static void BLE_SetFingerPrint(u8 type,u8 *buff, u8 len);
static void BLE_ClearFingerPrint(u8 type,u8 *buff, u8 len);
static void BLE_UpdateFingerPrint(u8 type,u8 *buff, u8 len);

static void BLE_GetPinCode(u8 type,u8 *buff, u8 len);
static void BLE_SetPinCode(u8 type,u8 *buff, u8 len);
static void BLE_ClearPinCode(u8 type,u8 *buff, u8 len);
static void BLE_UpdatePinCode(u8 type,u8 *buff, u8 len);
//static void BLE_GetAllPinCode(u8 type,u8 *buff, u8 len);
static void BLE_ChangeMasterCode(u8 type,u8 *buff, u8 len);


static u8 ble_sequenceNumber = 0;

static const BLE_CommandInfo_t bleListCommand[] = 
{
    {SEND_FIRST_TIME        ,BLE_SendFirstTime},
    {SEND_FIRST_TIME_1      ,BLE_SendFirstTime1},
    {SEND_FIRST_TIME_2      ,BLE_SendFirstTime2},
    {JOIN_NETWORK_RESULT_CMD,BLE_JoinNetworkResult},
    {TOGGLE_NETWORK_CMD     ,BLE_ToggleNetwork},
    {GET_NETWORK_INFO_CMD   ,BLE_GetNetworkInfo},
    {CHANGE_LOCK_STATE_CMD  ,BLE_ChangeLockState},
    {FINGER_PRINT_LOCK_CMD  ,BLE_FingerPrint},
    {DEVICE_ANNOUNCE        ,BLE_DeviceAnnounce},
    {SET_LOCK_CMD           ,BLE_SetLock},
    {GET_LOCK_CMD           ,BLE_GetLock},
    {GET_BATTERY_CMD        ,BLE_GetBatterry},
    {CHANGE_LANGUAGE_CMD    ,BLE_ChangeLanguage},
    {UPDATE_LANGUAGE_CMD    ,BLE_UpdateLanguage},
    {SET_FINGERPRINT_CMD    ,BLE_SetFingerPrint},
    {UPDATE_FINGERPRINT_CMD ,BLE_UpdateFingerPrint},
    {CLEAR_FINGERPRINT_CMD  ,BLE_ClearFingerPrint},
    {GET_PIN_CODE_CMD       ,BLE_GetPinCode},
    {SET_PIN_CODE_CMD       ,BLE_SetPinCode},
    {UPDATE_PIN_CODE_CMD    ,BLE_UpdatePinCode},
    {CLEAR_PIN_CODE_CMD     ,BLE_ClearPinCode},
    {CHANGE_MASTER_CODE_CMD ,BLE_ChangeMasterCode}
};


void BLE_CheckCommandExitsAndExecute(u8 command, u8 type,u8* buff, u8 len)
{
    for(int i = 0; i < sizeof(bleListCommand)/sizeof(BLE_CommandHandle_t); i++)
    {
        if(command == bleListCommand[i].cmdId)
        {
            if(bleListCommand[i].cmdHandle != NULL)
            {
                bleListCommand[i].cmdHandle(type, buff, len);
				return;
            }
        }
    }
}


void BLE_CommandRespond(u8 command, u8 type,u8* buff, u8 len)
{
    u8 sendBuff[BLUETOOTH_COMMAND_HEADER_SIZE+BLUETOOTH_COMMAND_MAX_LENGH+1];

    sendBuff[0]=command;
    sendBuff[1]=type;
    sendBuff[2]=ble_sequenceNumber++;
    sendBuff[3]=len;

    memcpy(&sendBuff[4],buff,len);
    sendBuff[len+4]=XOR_Caculator(sendBuff,0,len+4);

    BLUETOOTH_Send(sendBuff,len+5);
}


static void BLE_JoinNetworkResult(u8 type,u8 *buff, u8 len)
{
  
}

static void BLE_ToggleNetwork(u8 type,u8 *buff, u8 len)
{
 
}

static void BLE_GetNetworkInfo(u8 type,u8 *buff, u8 len)
{

}

static void BLE_ChangeLockState(u8 type,u8 *buff, u8 len)
{

}

static void BLE_FingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void BLE_SetLock(u8 type,u8 *buff, u8 len)
{
    ble_SetLock = 1;
}

static void BLE_GetLock(u8 type,u8 *buff, u8 len)
{

}

static void BLE_GetBatterry(u8 type,u8 *buff, u8 len)
{

}
static void BLE_ChangeLanguage(u8 type,u8 *buff, u8 len)
{

}
static void BLE_UpdateLanguage(u8 type,u8 *buff, u8 len)
{

}

static void BLE_SetFingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void BLE_ClearFingerPrint(u8 type,u8 *buff, u8 len)
{

}
static void BLE_UpdateFingerPrint(u8 type,u8 *buff, u8 len)
{

}

static void BLE_GetPinCode(u8 type,u8 *buff, u8 len)
{

}

static void BLE_SetPinCode(u8 type,u8 *buff, u8 len)
{
}

static void BLE_ClearPinCode(u8 type,u8 *buff, u8 len)
{

}
static void BLE_UpdatePinCode(u8 type,u8 *buff, u8 len)
{
    
}
//static void BLE_GetAllPinCode(u8 type,u8 *buff, u8 len)
//{
//
//}
static void BLE_ChangeMasterCode(u8 type,u8 *buff, u8 len)
{
    
}
  
static void BLE_SendFirstTime(u8 type,u8 *buff, u8 len)
{

}
static void BLE_SendFirstTime1(u8 type,u8 *buff, u8 len)
{

}
static void BLE_SendFirstTime2(u8 type,u8 *buff, u8 len)
{

}

static void BLE_DeviceAnnounce(u8 type,u8 *buff, u8 len)
{

}

