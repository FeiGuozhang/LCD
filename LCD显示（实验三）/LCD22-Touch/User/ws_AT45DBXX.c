/*********************************************************************************************************
*
* File                : ws_AT45DBXX.c
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 4.20
* Version             : V1.0
* By                  : 
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

#include "stm32f0xx.h"
//#include "usart.h"
#include "ws_AT45DBXX.h"

void AT45DBXX_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	SPI_Configuration();
//	printf("SPI is ready!\r\n");

	/*RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);*/
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC,&GPIO_InitStruct);
	
	AT45DBXX_Disable;
}

static void AT45DBXX_BUSY(void)
{
	uint8_t AT45DBXXStruct;

	AT45DBXX_Enable;
	SPI1_Send_byte(READ_STATE_REGISTER);
	do
	{AT45DBXXStruct = SPI1_Receive_byte();}
	 
	while(!(AT45DBXXStruct & 0x80));
	AT45DBXX_Disable;	
}

void AT45DBXX_Read_ID(uint8_t *IData)
{
	uint8_t i;
	AT45DBXX_BUSY();
	AT45DBXX_Enable;
	SPI1_Send_byte(Read_ID); //÷¥––∂¡»°id√¸¡Ó		  	
  	for(i=0;i<4;i++)
  	{
  		IData[i] = SPI1_Receive_byte();
  	}
  	AT45DBXX_Disable;
}

static void write_buffer(uint16_t BufferOffset,uint8_t Data)
{			
	AT45DBXX_Enable;
	SPI1_Send_byte(0x84);			
	SPI1_Send_byte(0xff);
	SPI1_Send_byte((uint8_t)BufferOffset>>8);
	SPI1_Send_byte((uint8_t)BufferOffset);		
	SPI1_Send_byte(Data);
	AT45DBXX_Disable;
}

static uint8_t read_buffer(uint16_t BufferOffset)
{		
	uint8_t temp;
	AT45DBXX_Enable;
 	SPI1_Send_byte(0xd4);
	SPI1_Send_byte(0xff);
	SPI1_Send_byte((uint8_t)BufferOffset>>8);
	SPI1_Send_byte((uint8_t)BufferOffset);
	temp=SPI1_Receive_byte();
	AT45DBXX_Disable;
	return temp;		
}
