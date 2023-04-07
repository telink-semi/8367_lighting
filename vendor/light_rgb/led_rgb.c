/********************************************************************************************************
 * @file	led_rgb.c
 *
 * @brief	This is the source file for TLSR8231
 *
 * @author	Telink
 * @date	May 12, 2019
 *
 * @par     Copyright (c) 2018, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *
 *          Licensed under the Apache License, Version 2.0 (the "License");
 *          you may not use this file except in compliance with the License.
 *          You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 *          Unless required by applicable law or agreed to in writing, software
 *          distributed under the License is distributed on an "AS IS" BASIS,
 *          WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *          See the License for the specific language governing permissions and
 *          limitations under the License.
 *
 *******************************************************************************************************/
//#include "../../common.h"
#include "../../drivers.h"
#include "../../user_drivers.h"
#include "state.h"
#include "frame.h"
#include "led_rgb.h"
#include "user_pwm.h"
/***********************************************************
 * 函数功能：RGB灯开
 * 参       数：
 * 返 回  值：
 **********************************************************/
void led_on_rgb_func(void)
{
	led_red_target=led_control.rgb_value[0];
	led_green_target=led_control.rgb_value[1];
	led_blue_target=led_control.rgb_value[2];
	led_red_cur=0;
	led_green_cur=0;
	led_blue_cur=0;
	led_rgb_state_change_flag=1;
}
/***********************************************************
 * 函数功能：RGB灯关
 * 参       数：
 * 返 回  值：
 **********************************************************/
void led_rgb_off_func(void)
{
	led_red_target=0;
	led_green_target=0;
	led_blue_target=0;
	led_rgb_state_change_flag=1;
}
/***********************************************************
 * 函数功能：设置RGB灯的目标亮度，渐变
 * 参       数：Red_v     红灯的PWM值
 *        Green_v   绿灯的PWM值
 *        Blue_v    蓝灯的PWM值
 * 返 回  值：
 **********************************************************/
void led_rgb_set_func(unsigned short Red_v,unsigned short Green_v,unsigned short Blue_v)
{
	led_red_target=Red_v;
	led_green_target=Green_v;
	led_blue_target=Blue_v;
	led_rgb_state_change_flag=1;//状态更新标志
}
/***********************************************************
 * 函数功能：直接设置RGB灯的PWM值
 * 参       数：Red_v     红灯的PWM值
 *        Green_v   绿灯的PWM值
 *        Blue_v    蓝灯的PWM值
 * 返 回  值：
 **********************************************************/
void led_set_rgb_power_func(unsigned short Red_v,unsigned short Green_v,unsigned short Blue_v)
{
	PWM_DutyValueSet(PWM2, Red_v);
	PWM_DutyValueSet(PWM1, Green_v);
	PWM_DutyValueSet(PWM3, Blue_v);
}
