/********************************************************************************************************
 * @file	key_def.h
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

#if 0
#define KEY_NONE_CMD     			0x0
#define KEY_ON_CMD       			0x1
#define KEY_OFF_CMD      			0x2
#define KEY_LUMINANT_INCREASE_CMD   0x3
#define KEY_LUMINANT_DECREASE_CMD   0x4
#define KEY_CHROMA_INCREASE_CMD     0x5
#define KEY_CHROMA_DECREASE_CMD     0x6
#define KEY_SET_LUMI_CHROMA_CMD     0x7
#define KEY_QUICK_LOW_LIGHT_CMD     0x8
#define KEY_PAIRE_CODE_CMD          0x9
#define KEY_CLEAR_CODE_CMD          0xa
#define KEY_SET_RGB_CMD             0xb
#define KEY_BREATH_RGB_MODE_CMD     0xc
#endif

typedef enum{
	KEY_NONE_CMD=0,                //无操作命令
	KEY_ON_CMD,                    //开灯命令
	KEY_OFF_CMD,                   //关灯命令
	KEY_LUMINANCE_INC_CMD,         //亮度加
	KEY_LUMINANCE_DEC_CMD,         //亮度减
	KEY_CHROME_INC_CMD,            //色温加
	KEY_CHROME_DEC_CMD,            //色温减
	KEY_SET_CHRO_LUMI_CMD,         //设置色温、亮度
	KEY_NIGHT_CMD,                 //夜灯
	KEY_PAIRE_CODE_CMD,            //对码
	KEY_CLEAR_CODE_CMD,            //清码
	KEY_SET_RGB_CMD,               //设置RGB
	KEY_BREATH_RGB_MODE_CMD,       //RGB呼吸模式
	LED_LAST_CMD,
}LED_Control_CMD_e;
