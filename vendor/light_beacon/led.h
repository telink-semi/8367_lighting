/********************************************************************************************************
 * @file	led.h
 *
 * @brief	This is the header file for TLSR8231
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
#pragma once

#define MAX_LUMINANCE        1000      //亮度的级数
#define MAX_LUMINANCE_INDEX  13        //亮度的级数
#define MAX_CHROME           100       //亮度值
#define MAX_CHROME_INDEX     10
#define LOW_LIGHT_LUMINACE   20        //小夜灯的值

void led_luminace_segment_set_func(unsigned char seg_index);
void led_init_func(void);
void led_pwm_control_func(int lumina, int chroma);
void led_task_process_func(void);
void led_flash_updata(unsigned char Flash_cnt);
void led_event_proc_func(unsigned char Cmd);
void led_set_lumi_chrome_func(unsigned short Lumi,unsigned short Chroma);
typedef enum{
	LED_NONE_CMD=0,
	LED_ON_CMD,
	LED_OFF_CMD,
	LED_LUMINANCE_INC_CMD,
	LED_LUMINANCE_DEC_CMD,
	LED_CHROME_INC_CMD,
	LED_CHROME_DEC_CMD,
	LED_SET_CHRO_LUMI_CMD,
	LED_NIGHT_CMD,
	LED_LAST_CMD,
}Led_control_cmd;
