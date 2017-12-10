#include "stm32f0xx.h"
#include "LTM022A69B.h"
#include "User_systick.h"
#include "usart.h"
#include "Touch.h"


 unsigned char read_res ;

 typedef struct 
{
	unsigned int  x;//LCD坐coordinates

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
	
	lcd_init();																					                                                                             //LCD初始化
	lcd_init();
	TOUCH_init();
	  //lcd_display_char(10, BLACK, WHITE, 10, 2 );
     lcd_display_string( "    : 201521094011            ", BLACK, WHITE, 0, 1 );						//第二行显示学号
	 lcd_display_string( "    :                         ", BLACK, WHITE, 0, 2 );													//第三行显示空行
     lcd_display_string( "    : 201521094025            ", BLACK, WHITE, 0, 3 );
	 lcd_display_string( "    :                         ", BLACK, WHITE, 0, 4 );
	 lcd_display_GB2312( 0, BLACK,WHITE,0,1);																													//第二行第一位显示汉字“学“ 
	 lcd_display_GB2312( 1, BLACK,WHITE,1,1);																													//第二行第二位显示汉字“号”
	 lcd_display_GB2312( 0, BLACK,WHITE,0,3);																													//第四行第一位显示汉字“学”
	 lcd_display_GB2312( 1, BLACK,WHITE,1,3);																													//第四行第二位显示汉字“号”

	 lcd_display_GB2312( 2, BLACK,WHITE,0,2);																													//姓
	 lcd_display_GB2312( 3, BLACK,WHITE,1,2);																													//名
	 lcd_display_GB2312( 2, BLACK,WHITE,0,4);																													//姓
	 lcd_display_GB2312( 3, BLACK,WHITE,1,4);																													//名

	 lcd_display_GB2312( 4, BLACK,WHITE,3,2);																												  //费
	 lcd_display_GB2312( 5, BLACK,WHITE,4,2);																												  //国
	 lcd_display_GB2312( 6, BLACK,WHITE,5,2);																												  //璋
	 lcd_display_GB2312( 7, BLACK,WHITE,3,4);                                                           //龚
	 lcd_display_GB2312( 8, BLACK,WHITE,4,4);                                                           //明
	 lcd_display_GB2312( 9, BLACK,WHITE,5,4);																													//川
	 lcd_display_32x29( 0, BLACK,WHITE,3,5);																													//二号楷体“费”
	 lcd_display_32x29( 1, BLACK,WHITE,4,5);																													//二号楷体“国”
	 lcd_display_32x29( 2, BLACK,WHITE,5,5);																													//二号楷体“璋”
	 lcd_display_32x29( 3, BLACK,WHITE,3,6);																													//二号楷体“龚”
	 lcd_display_32x29( 4, BLACK,WHITE,4,6);																													//二号楷体“明”
	 lcd_display_32x29( 5, BLACK,WHITE,5,6);																													//二号楷体“川”

	 lcd_display_image( "img", 160,64,8,8);																																//显示小字号“五”

	while(1)
	{
			read_res=Read_Continue();
 		lcd_draw_dot(BLACK,(touch_dot.x-20),(touch_dot.y-2));

	}
}
