/********************************************************************************************************
 * @file	otp.h
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
#ifndef _OTP_H_
#define _OTP_H_


//void otp_init_readwrite(void);
//void otp_init_read(void);
//void otp_init(void);
void otp_write(unsigned short addr, unsigned char  value);
void otp_stop_write(void);
unsigned char otp_read(unsigned short addr);
unsigned char otp_normal_read(unsigned short addr);

#endif
