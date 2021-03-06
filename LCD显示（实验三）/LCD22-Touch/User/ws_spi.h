/*********************************************************************************************************
*
* File                : ws_spi.h
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

#ifndef __SPI_H
#define __SPI_H

static void SPI_Rcc_Configuration(void);
static void GPIO_Configuration(void);
void SPI_Configuration(void);
void SPI1_Send_byte(uint16_t data);
uint16_t SPI1_Receive_byte(void);

#endif /*__SPI_H*/
