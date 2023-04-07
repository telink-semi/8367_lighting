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

typedef enum{
	KEY_NONE_CMD=0,
	KEY_ON_CMD,
	KEY_OFF_CMD,
	KEY_LUMINANCE_INC_CMD,
	KEY_LUMINANCE_DEC_CMD,
	KEY_CHROME_INC_CMD,
	KEY_CHROME_DEC_CMD,
	KEY_SET_CHRO_LUMI_CMD,
	KEY_NIGHT_CMD,
	KEY_PAIRE_CODE_CMD,
	KEY_CLEAR_CODE_CMD,
	KEY_SET_RGB_CMD,
	KEY_BREATH_RGB_MODE_CMD,
	LED_LAST_CMD,
}LED_Control_CMD_e;

