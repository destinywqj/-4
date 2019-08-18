#include "pwm.h"
#include "led.h"
#include "time.h"
void TIM3_PWM_Init(u16 arr,u16 psc)
{
GPIO_InitTypeDef GPIO_InitSturcture;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef  TIM_OCInitTypeStrue;
	
	
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO , ENABLE);
		
	GPIO_InitSturcture.GPIO_Mode= GPIO_Mode_AF_PP;
	GPIO_InitSturcture.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitSturcture.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitSturcture);
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE );

TIM_TimeBaseStructure.TIM_Period = arr; //�����Զ���װ�ؼĴ������ڵ�ֵ
TIM_TimeBaseStructure.TIM_Prescaler =psc; //����ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM ���ϼ���
TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //�ڳ�ʼ�� TIM3
	
 TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM2;
 TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCPolarity_High;
 TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable;
 TIM_OC2Init(TIM3,&TIM_OCInitTypeStrue);
 
 TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
 TIM_Cmd(TIM3,ENABLE);
 }
