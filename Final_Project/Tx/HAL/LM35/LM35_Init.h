/*
 * LM35_Interface.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_LM35_LM35_INIT_H_
#define HAL_LM35_LM35_INIT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_Init.h"

#include "LM35_Config.h"

void HLM35_VoidLM35Init(void);
u16  HLM35_u16LM35Read(void);

#endif /* HAL_LM35_LM35_INIT_H_ */
