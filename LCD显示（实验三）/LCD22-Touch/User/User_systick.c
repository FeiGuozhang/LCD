/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "User_systick.h"

static uint32_t TimingDelay;

void delay_1ms(uint32_t delay_conter)
{
	SysTick_Config((uint32_t)6000);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);

	TimingDelay = delay_conter;
	while(TimingDelay!=0);
}

void delay_10us(uint32_t delay_conter)
{
	SysTick_Config((uint32_t)60);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);

	TimingDelay = delay_conter;
	while(TimingDelay!=0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}



