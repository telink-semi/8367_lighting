/********************************************************************************************************
 * @file	set_drv.h
 *
 * @brief	This is the head file for TLSR8231
 *
 * @author	Telink
 * @date	May 12, 2019
 *
 * @par		Copyright (c) 2018, Telink Semiconductor (Shanghai) Co., Ltd.
 *			All rights reserved.
 *
 *          The information contained herein is confidential property of Telink
 *          Semiconductor (Shanghai) Co., Ltd. and is available under the terms
 *          of Commercial License Agreement between Telink Semiconductor (Shanghai)
 *          Co., Ltd. and the licensee or the terms described here-in. This heading
 *          MUST NOT be removed from this file.
 *
 *          Licensee shall not delete, modify or alter (or permit any third party to delete, modify, or
 *          alter) any information contained herein in whole or in part except as expressly authorized
 *          by Telink semiconductor (shanghai) Co., Ltd. Otherwise, licensee shall be solely responsible
 *          for any claim to the extent arising out of or relating to such deletion(s), modification(s)
 *          or alteration(s).
 *
 *          Licensees are granted free, non-transferable use of the information in this
 *          file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided.
 *
 *******************************************************************************************************/
#pragma once

typedef enum{
	SB_MODE=0,
	TPLL_MODE
}t_private_modeTypeDef;


unsigned char rf_rx_buffer_get(void);
void rf_set_access_code_len(unsigned char len);
void rf_set_access_code_value(unsigned char pipe,unsigned long long accesscode);
void rf_set_t_private_mode(t_private_modeTypeDef mode,unsigned char len);
void swap_data(unsigned char *data,unsigned char len);
void rf_set_t_private_address(unsigned char pipe,unsigned long long accesscode);
void rf_start_t_private_ptx  (unsigned char* RF_TxAddr ,unsigned int RF_StartTick,unsigned int RxTimeoutUs,unsigned int Retry);
void rf_start_t_private_prx  (unsigned char* RF_TxAddr ,unsigned int RF_StartTick);
void rf_set_t_private_timing  (unsigned short retry_delay,unsigned short rx_delay,unsigned short tx_delay);
void rf_set_retry_delay(unsigned short timing);
void rf_set_rxstl(unsigned short timing);
void rf_set_txstl(unsigned short timing);
unsigned int Rf_RCV_PKT_Valid(unsigned char* p);

