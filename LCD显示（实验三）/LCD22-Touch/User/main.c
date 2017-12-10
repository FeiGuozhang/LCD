#include "stm32f0xx.h"
#include "LTM022A69B.h"
#include "User_systick.h"
#include "usart.h"
#include "Touch.h"


 unsigned char read_res ;

 typedef struct 
{
	unsigned int  x;//LCD��coordinates

	unsigned int  y;
	unsigned long x_ad_val; //ADC value
	unsigned long y_ad_val;						   	    
	unsigned char  pen_status;//The pen of the state
			  
}_touch_dot;

extern _touch_dot touch_dot;

int main(void)
{
//	SystemInit();
	//USART_Configuration();
	
	lcd_init();																					                                                                             //LCD��ʼ��
	lcd_init();
	TOUCH_init();
	  //lcd_display_char(10, BLACK, WHITE, 10, 2 );
     lcd_display_string( "    : 201521094011            ", BLACK, WHITE, 0, 1 );						//�ڶ�����ʾѧ��
	 lcd_display_string( "    :                         ", BLACK, WHITE, 0, 2 );													//��������ʾ����
     lcd_display_string( "    : 201521094025            ", BLACK, WHITE, 0, 3 );
	 lcd_display_string( "    :                         ", BLACK, WHITE, 0, 4 );
	 lcd_display_GB2312( 0, BLACK,WHITE,0,1);																													//�ڶ��е�һλ��ʾ���֡�ѧ���� 
	 lcd_display_GB2312( 1, BLACK,WHITE,1,1);																													//�ڶ��еڶ�λ��ʾ���֡��š�
	 lcd_display_GB2312( 0, BLACK,WHITE,0,3);																													//�����е�һλ��ʾ���֡�ѧ��
	 lcd_display_GB2312( 1, BLACK,WHITE,1,3);																													//�����еڶ�λ��ʾ���֡��š�

	 lcd_display_GB2312( 2, BLACK,WHITE,0,2);																													//��
	 lcd_display_GB2312( 3, BLACK,WHITE,1,2);																													//��
	 lcd_display_GB2312( 2, BLACK,WHITE,0,4);																													//��
	 lcd_display_GB2312( 3, BLACK,WHITE,1,4);																													//��

	 lcd_display_GB2312( 4, BLACK,WHITE,3,2);																												  //��
	 lcd_display_GB2312( 5, BLACK,WHITE,4,2);																												  //��
	 lcd_display_GB2312( 6, BLACK,WHITE,5,2);																												  //�
	 lcd_display_GB2312( 7, BLACK,WHITE,3,4);                                                           //��
	 lcd_display_GB2312( 8, BLACK,WHITE,4,4);                                                           //��
	 lcd_display_GB2312( 9, BLACK,WHITE,5,4);																													//��
	 lcd_display_32x29( 0, BLACK,WHITE,3,5);																													//���ſ��塰�ѡ�
	 lcd_display_32x29( 1, BLACK,WHITE,4,5);																													//���ſ��塰����
	 lcd_display_32x29( 2, BLACK,WHITE,5,5);																													//���ſ��塰谡�
	 lcd_display_32x29( 3, BLACK,WHITE,3,6);																													//���ſ��塰����
	 lcd_display_32x29( 4, BLACK,WHITE,4,6);																													//���ſ��塰����
	 lcd_display_32x29( 5, BLACK,WHITE,5,6);																													//���ſ��塰����

	 lcd_display_image( "img", 160,64,8,8);																																//��ʾС�ֺš��塱

	while(1)
	{
			read_res=Read_Continue();
 		lcd_draw_dot(BLACK,(touch_dot.x-20),(touch_dot.y-2));

	}
}
