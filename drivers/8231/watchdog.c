/********************************************************************************************************
 * @file	watchdog.c
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
#include "register.h"
#include "gpio.h"
#include "watchdog.h"
/**
 * @brief     This function set the seconds period.It is likely with WD_SetInterval.
 *            Just this function calculate the value to set the register automatically .
 * @param[in] period_s - The seconds to set. unit is second
 * @param[in] tick_per_ms - set the tick of every ms
 * @return    none
 */
void wd_set_interval_ms(unsigned int period_ms,unsigned long int tick_per_ms)
{
	static unsigned short tmp_period_ms = 0;
	tmp_period_ms = (period_ms*tick_per_ms>>18);
	reg_tmr2_tick = 0x00000000;    //reset tick register
	reg_tmr_ctrl &= (~FLD_TMR_WD_CAPT);
	reg_tmr_ctrl |= (tmp_period_ms<<9); //set the capture register
}

#if (BLE_SDK_EN)
/**
 * @brief     This function set the seconds period.It is likely with WD_SetInterval.
 *            Just this function calculate the value to set the register automatically .
 * @param[in] ms - The seconds to set. unit is second
 * @return    none
 */
static inline void wd_set_interval(int ms)	//  in ms
{
	SET_FLD_V(reg_tmr_ctrl, FLD_TMR_WD_CAPT, (ms * (CLOCK_RUN_CLOCK_HZ/1000) >> WATCHDOG_TIMEOUT_COEFF), FLD_TMR2_MODE, 0);
	reg_tmr2_tick = 0;
}
#endif
