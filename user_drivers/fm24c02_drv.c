/********************************************************************************************************
 * @file	fm24c02_drv.c
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
//#include "../common.h"
#include "../drivers.h"
#include "fm24c02_drv.h"

void fm24c02_init_func(unsigned int scl,unsigned int sda)
{
	extern unsigned int i2c_pin_scl;
	extern unsigned int i2c_pin_sda;
	i2c_pin_scl = scl;
	i2c_pin_sda = sda;
	gpio_set_up_down_resistor(i2c_pin_scl,GPIO_PULL_UP_10K);
	gpio_set_up_down_resistor(i2c_pin_sda,GPIO_PULL_UP_10K);
//	i2c_master_init(FM24C02ID,40);
//	i2c_set_pin(PinGrp);
//	CFG_PC4_MSD();
//	CFG_PC5_MCK();
	i2c_init();
}

unsigned int fm24c02_read_func(int address)
{
	unsigned char dat;
	dat=i2c_read(0xa0,address);
	return dat;
}

void fm24c02_write_func(int address, int data)
{
	static unsigned int Prev_wr_timing=0;

	while(!timeout_us(Prev_wr_timing, 5000)){
	};
	i2c_write(0xa0,address, data);
	Prev_wr_timing = get_sys_tick();

}

