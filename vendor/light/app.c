/********************************************************************************************************
 * @file	app.c
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
#include "app_config.h"
#include "../../user_drivers.h"
#include "rf_control.h"
#include "led.h"
#include "time_event.h"
#include "pairing_op.h"
#include "user_pwm.h"
#include "../../user_drivers/i2c_drv.h"

extern unsigned char led_on_cnt;
unsigned char g_state;
unsigned int  sys_run_tick;

#define  DEBUG   1
/***********************************************************
 * 函数功能：初始化PWM
 * 参       数：
 * 返 回  值：
 **********************************************************/
void set_pwm_init_func(void)
{
//	pwm_set_clk(CLOCK_SYS_CLOCK_HZ,16000);
	reg_rst1 &= ~FLD_RST1_PWM;
	reg_clk_en1 |= FLD_CLK1_PWM_EN;
#if DEBUG
	gpio_set_func(GPIO_PA7,AS_PWM0);
	gpio_set_func(GPIO_PA3,AS_PWM4);
#else
	gpio_set_func(GPIO_PB1,AS_PWM1);
	gpio_set_func(GPIO_PB4,AS_PWM2);
#endif
	user_PWMInit(PWM0,1000,16000);
	user_PWMInit(PWM4,1000,16000);
	PWM_DutyValueSet(PWM0,0);
	PWM_DutyValueSet(PWM4,0);
	pwm_start(PWM0);
	pwm_start(PWM4);
}
/***********************************************************
 * 函数功能：系统状态检测
 * 参       数：
 * 返 回  值：
 **********************************************************/
void check_sys_state_func(void)
{
	if(g_state==PAIRRING_STATE){
		if(timeout_us(sys_run_tick,6000000)){//上电6s没有收到开灯键，系统进入正常模式
			g_state=NORMAL_STATE;
		}
	}else if(g_state==CLEARCODE_STATE){//系统收到开灯健
		if(timeout_us(sys_run_tick,500000)){//收到开灯按键后，超过500ms没有收到下一次开灯健
			if(led_on_cnt==1){//只收到1次开灯健，则认为是对码
				led_flash_updata(3);//闪烁3次
				pair_id_save_func();//保存参数
			}
			g_state=NORMAL_STATE;//系统进入正常模式
		}
	}
}

void user_init(void)
{
	rf_init_func();
	fm24c02_init_func(GPIO_PA5,GPIO_PB6);
	set_pwm_init_func();
	led_init_func();
	g_state=PAIRRING_STATE;
	sys_run_tick=get_sys_tick();
	irq_enable();
}


void main_loop(void)
{
	rf_packget_pro_func();
	led_task_process_func();
	time_event_process_func();
	check_sys_state_func();
}
