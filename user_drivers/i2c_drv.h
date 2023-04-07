/********************************************************************************************************
 * @file	i2c_drv.h
 *
 * @brief	This is the head file for TLSR8231
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

//#include "../../proj/common/types.h"



volatile unsigned int i2c_pin_scl;
volatile unsigned int i2c_pin_sda;

// Pulling the line to ground is considered a logical zero while letting the line float is a logical one.   http://en.wikipedia.org/wiki/I%C2%B2C
static inline void i2c_scl_out(int v){
	gpio_set_output_en(i2c_pin_scl, (!v));
}

// Pulling the line to ground is considered a logical zero while letting the line float is a logical one.   http://en.wikipedia.org/wiki/I%C2%B2C
static inline void i2c_sda_out(int v){
	gpio_set_output_en(i2c_pin_sda, (!v));
}


void i2c_init(void);
void i2c_write(unsigned char id, unsigned char addr, unsigned char dat);
unsigned char i2c_read(unsigned char id, unsigned char addr);
void i2c_burst_read(unsigned char id, unsigned char addr, unsigned char *p, unsigned char n);

