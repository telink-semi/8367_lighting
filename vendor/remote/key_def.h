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

#define KEY_NONE     			0x0
#define KEY_ON       			0x1
#define KEY_OFF      			0x2
#define KEY_LUMINANT_INCREASE   0x3
#define KEY_LUMINANT_DECREASE   0x4
#define KEY_CHROMA_INCREASE     0x5
#define KEY_CHROMA_DECREASE     0x6
//#define KEY_SET_LUMINANT        0x7
//#define KEY_SET_CHROMA          0x8
#define KEY_QUICK_LOW_LIGHT     0x8
#define KEY_SET_LUMI_CHROMA     0x7

#define KEY_ALL_ON				0x1f
#define KEY_ALL_OFF				0x2f


#define GROUP_1				1
#define GROUP_2				2
#define GROUP_3				4
#define GROUP_4				8
#define GROUP_ALL				0x0f
