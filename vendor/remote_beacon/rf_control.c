/********************************************************************************************************
 * @file	rf_control.c
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
#include "frame.h"
#include "rf_control.h"


const unsigned char rf_channel[4]={1,24,51,76};


void rf_init_func(void)
{
#if 0
//	rf_drv_init(RF_MODE_BLE_1M_NO_PN);
	rf_set_access_code_len(4);
//	rf_set_access_code_value(0,0x8e89bed6);
	rf_set_ble_crc_adv();
	rf_set_ble_access_code_adv();
	rf_set_rx_buff(rx_packet,RX_PACKGET_SIZE,1);
	rf_set_power_level_index(RF_POWER_7dBm);
	rf_set_trx_state(RF_MODE_RX,rf_channel[0]);
	rf_irq_clr_mask(0xffff);                      //先关掉所有的RF中断
	rf_irq_set_mask(FLD_RF_IRQ_RX);//打开RF RX中断
	irq_set_mask(FLD_IRQ_ZB_RT_EN);//开RF总中断
#else
	rf_set_ble_crc_adv();
	rf_set_ble_access_code_adv();
	rf_set_power_level_index(RF_POWER_7dBm);
	rf_set_ble_channel(37);
	rf_set_tx_rx_off();
	rf_irq_clr_mask(0xffff);                      //先关掉所有的RF中断
	rf_irq_set_mask(FLD_RF_IRQ_RX);//打开RF RX中断
	irq_set_mask(FLD_IRQ_ZB_RT_EN);//开RF总中断
	irq_enable();//开系统总中断
	READ_REG16(0xf04)=0x40;
	rf_set_tx_on();
#endif
}

void send_package_data_func(void)
{
	unsigned char i;
	for(i=0;i<3;i++){
//		rf_set_trx_state(RF_MODE_TX,rf_channel[i]);
		rf_set_ble_channel(37+i);
		delay_us(200);
		rf_start_stx((void *)&led_remote,get_sys_tick()+32);
		while(!rf_is_tx_finish());
		rf_clr_tx_finish();
	}
}
