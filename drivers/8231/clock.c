/********************************************************************************************************
 * @file	clock.c
 *
 * @brief	This is the clock driver file for TLSR8231
 *
 * @author	Telink
 * @date	May 9, 2019
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
#include "register.h"
#include "clock.h"
#include "irq.h"
#include "analog.h"
#include "timer.h"


unsigned char sdk_clock_state = 0;


#if(BLE_SDK_EN)

/**
 * @brief       This function to select the system clock source.
 * @return      none
 */
void clockInit(){
	if(CLOCK_USE_RC_BROADCAST && !sdk_clock_state){
		reg_clk_sel = 0;
	}else if(CLOCK_SYS_TYPE == CLOCK_TYPE_PLL){
		if(CLOCK_RUN_CLOCK_HZ == 48000000){
			reg_clk_sel = MASK_VAL(FLD_CLK_SEL_DIV, 0, FLD_CLK_SEL_SRC, CLOCK_PLL_48M_NO_DIV);
		}else if(CLOCK_RUN_CLOCK_HZ == 32000000){
			reg_clk_sel = MASK_VAL(FLD_CLK_SEL_DIV, 1, FLD_CLK_SEL_SRC, CLOCK_PLL_32M_DIV);
		}else{
			reg_clk_sel = MASK_VAL(FLD_CLK_SEL_DIV, (CLOCK_PLL_CLOCK / CLOCK_RUN_CLOCK_HZ), FLD_CLK_SEL_SRC, CLOCK_SEL_HS_DIV);
		}
	}else{

		if(CLOCK_RUN_CLOCK_HZ <= 16000000){
			reg_clk_sel = MASK_VAL(FLD_CLK_SEL_DIV, (16000000 / CLOCK_RUN_CLOCK_HZ), FLD_CLK_SEL_SRC, CLOCK_RC_16M_DIV);
		}
	}
}
#else
/**
 * @brief       This function to select the system clock source.
 * @param[in]   SYS_CLK - the clock source of the system clock.
 * @return      none
 */
void clock_init(SYS_CLK_TYPEDEF SYS_CLK)
{
	WRITE_REG8(0x70,READ_REG8(0x70)&0xfe);
	WRITE_REG8(0x66,SYS_CLK);
}
#endif
/**
 * @brief     This function performs to select 24M as the system clock source.
 * @param[in] none.
 * @return    none.
 */
void rc_24m_cal (void)
{
	sub_wr_ana(0x83, 3, 6, 4);	//wait len
	sub_wr_ana(0x83, 0, 1, 1);	//sel calbr 24m
	sub_wr_ana(0x02, 1, 4, 4);	//manual off
	sub_wr_ana(0x83, 1, 0, 0);	//calbr en on
	while((analog_read(0x84) & 0x01) == 0);	//wait done
	unsigned char cap = analog_read(0x85);	//read 24m cap result
	analog_write(0x30, cap);		//write 24m cap into manual register
	sub_wr_ana(0x83, 0, 0, 0);	//calbr en off
	sub_wr_ana(0x02, 0, 4, 4);	//manual on

}

/**
 * @brief     This function performs to select 32K as the system clock source.
 * @param[in] none.
 * @return    none.
 */
void rc_32k_cal (void)
{
	sub_wr_ana(0x83, 3, 6, 4);	//wait len
	sub_wr_ana(0x83, 1, 1, 1);	//sel calbr 32k
	sub_wr_ana(0x02, 1, 2, 2);	//manual off
	sub_wr_ana(0x83, 1, 0, 0);	//calbr en on
	while((analog_read(0x84) & 0x01) == 0);	//wait done
	unsigned char cap = analog_read(0x85);	//read 32k cap result
	analog_write(0x2f, cap);		//write 32k cap into manual register
	sub_wr_ana(0x83, 0, 0, 0);	//calbr en off
	sub_wr_ana(0x02, 0, 2, 2);	//manual on
}

