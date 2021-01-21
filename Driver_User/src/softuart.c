#include "softuart.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"

static uint32_t tickcount = 0;

void Softuart_Handtick(void)
{
    tickcount++;
}

uint32_t Softuart_Gettick(void)
{
    return tickcount;
}

void Softuart_Config(uint32_t Baudrate)
{
    /* GPIOA Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    /* GPIOA Config */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOA, GPIO_Pin_11);
    
    /* TIM2 Clock enabale */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    /* PCLK1 = HCLK/4 */
    RCC_PCLK1Config(RCC_HCLK_Div4);
    /* TIM2 Config */
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = Baudrate;
    TIM_TimeBaseStructure.TIM_Prescaler = 288;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    /* TIM IT enable */
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

void Softuart_SendByte(uint8_t byte)
{
    setlow();
    uint8_t buff[8];
    for(uint8_t i = 0; i < 8; i++)
    {
        if(byte & 0x08 == 0x08)
        {
            buff[i] = 1;
        }else
        {
            buff[i] = 0;
        }
        byte >>= 1;
        
    }
    tickcount = 0;
    while(Softuart_Gettick() != 1);
    sethigh();
    for(uint8_t i = 0; i < 8; i++)
    {
        while (Softuart_Gettick() == i+1);
        if(buff[i] == 1)
        {
            setlow();
        }else
        {
            sethigh();
        }
    }
    while (Softuart_Gettick() == 9);
    setlow();
}

void Softuart_send_frame(uint8_t startbyte, uint8_t addressbyte,
                                    uint8_t databyte, uint8_t stopbyte)
{
    Softuart_SendByte(startbyte);
    Softuart_SendByte(addressbyte);
    Softuart_SendByte(databyte);
    Softuart_SendByte(stopbyte);
 
}

void Softuart_SendData(uint8_t* buff, uint8_t length)
{
    for(uint8_t i = 0; i < length; i++)
    {
        Softuart_SendByte(buff[i]);
    }
}